#include "NoticeUOSDAQ3.h"

enum EManipInterface {kInterfaceClaim, kInterfaceRelease};

struct dev_open {
   libusb_device_handle *devh;
   uint16_t vendor_id;
   uint16_t product_id;
   int serial_id;
   struct dev_open *next;
} *ldev_open = 0;

// internal functions *********************************************************************************
static int is_device_open(libusb_device_handle *devh);
static unsigned char get_serial_id(libusb_device_handle *devh);
static void add_device(struct dev_open **list, libusb_device_handle *tobeadded,
                       uint16_t vendor_id, uint16_t product_id, int sid);
static int handle_interface_id(struct dev_open **list, uint16_t vendor_id, uint16_t product_id,
                               int sid, int interface, enum EManipInterface manip_type);
static void remove_device_id(struct dev_open **list, uint16_t vendor_id, uint16_t product_id, int sid);
int USB3Read(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t count, 
             uint32_t addr, unsigned char *data);
libusb_device_handle* nkusb_get_device_handle(uint16_t vendor_id, uint16_t product_id, int sid);
int USB3ReadReg(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t addr);
int USB3Write(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t addr, uint32_t data);
int USB3Reset(uint16_t vendor_id, uint16_t product_id, unsigned char sid);

static int is_device_open(libusb_device_handle *devh)
{
// See if the device handle "devh" is on the open device list

  struct dev_open *curr = ldev_open;
  libusb_device *dev, *dev_curr;
  int bus, bus_curr, addr, addr_curr;

  while (curr) {
    dev_curr = libusb_get_device(curr->devh);
    bus_curr = libusb_get_bus_number(dev_curr);
    addr_curr = libusb_get_device_address(dev_curr);

    dev = libusb_get_device(devh);
    bus = libusb_get_bus_number(dev);
    addr = libusb_get_device_address(dev);

    if (bus == bus_curr && addr == addr_curr) return 1;
    curr = curr->next;
  }

  return 0;
}

static unsigned char get_serial_id(libusb_device_handle *devh)
{
// Get serial id of device handle devh. devh may or may not be on open device list 'ldev_open'.
// Returns 0 if error.
  int ret;
  if (!devh) {
    return 0;
  }
  unsigned char data[1];
  ret = libusb_control_transfer(devh, LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_ENDPOINT_IN, 0xD2, 0, 0, data, 1, 1000);

  if (ret < 0) {
    fprintf(stdout, "Warning: get_serial_id: Could not get serial id.\n");
    return 0;
  }

  return data[0];
}

static void add_device(struct dev_open **list, libusb_device_handle *tobeadded,
                       uint16_t vendor_id, uint16_t product_id, int sid)
{
// Add device to the open device list

  struct dev_open *curr;

  curr = (struct dev_open *)malloc(sizeof(struct dev_open));
  curr->devh = tobeadded;
  curr->vendor_id = vendor_id;
  curr->product_id = product_id;
  curr->serial_id = sid;
  curr->next  = *list;
  *list = curr;
}

static int handle_interface_id(struct dev_open **list, uint16_t vendor_id, uint16_t product_id,
                               int sid, int interface, enum EManipInterface manip_type)
{
// Manipulate interface on the device with specified vendor id, product id and serial id
// from open device list. Claim interface if manip_type == kInterfaceClaim, release interface
// if manip_type == kInterfaceRelease. If sid == NK_SID_ANY, all devices with given vendor id
// and product id are handled.

  int ret = 0;
  if (!*list) {
    ret = -1;
    return ret;
  }

  struct dev_open *curr = *list;
  struct libusb_device_descriptor desc;
  libusb_device *dev;

  while (curr) {
    dev =libusb_get_device(curr->devh);
    if (libusb_get_device_descriptor(dev, &desc) < 0) {
      // Ignore with message
      fprintf(stdout, "Warning: remove_device: could not get device device descriptior."
                          " Ignoring.\n");
      continue;
    }
    if (desc.idVendor == vendor_id && desc.idProduct == product_id
    && (sid == 0xFF || sid == get_serial_id(curr->devh))) { 
      // Match.
      if (manip_type == kInterfaceClaim) {
        if ((ret = libusb_claim_interface(curr->devh, interface)) < 0) {
          fprintf(stdout, "Warning: handle_interface_id: Could not claim interface (%d) on device (%u, %u, %u)\n",
                  interface, vendor_id, product_id, sid);
        }
      }
      else if (manip_type == kInterfaceRelease) {
        if ((ret =libusb_release_interface(curr->devh, interface)) < 0) {
          fprintf(stdout, "Warning: handle_interface_id: Could not release interface (%d) on device (%u, %u, %u)\n",
                  interface, vendor_id, product_id, sid);
        }
      }
      else {
        fprintf(stderr, "Error: handle_interface_id: Unknown interface handle request: %d\n.",
                manip_type);
              
        ret = -1;
        return ret;
      }
    }
    // Move forward
    curr = curr->next;
  }

  return ret;
}

static void remove_device_id(struct dev_open **list, uint16_t vendor_id, uint16_t product_id, int sid)
{
// Close and remove device with specified vendor id, product id and serial id
// from open device list. If sid == NK_SID_ANY, all devices with given vendor id
// and product id are removed.

  if (!*list) return;

  struct dev_open *curr = *list;
  struct dev_open *prev = 0;
  struct libusb_device_descriptor desc;
  libusb_device *dev;

  while (curr) {
    dev =libusb_get_device(curr->devh);
    if (libusb_get_device_descriptor(dev, &desc) < 0) {
      // Ignore with message
      fprintf(stdout, "Warning, remove_device: could not get device device descriptior." " Ignoring.\n");
      continue;
    }
    if (desc.idVendor == vendor_id && desc.idProduct == product_id
    && (sid == 0xFF || sid == get_serial_id(curr->devh))) { 
      // Match.
      if (*list == curr) { 
        // Update head, remove current element and move cursor forward.
        *list = curr->next;
        libusb_close(curr->devh);
        free(curr); 
        curr = *list;
      }
      else {
        // Update link, remove current element and move cursor forward.
        prev->next = curr->next;
        libusb_close(curr->devh);
        free(curr); 
        curr = prev->next;
      }
    }
    else {
      // No match. Move cursor forward.
      prev = curr;
      curr = curr->next;
    }    
  }
}

libusb_device_handle* nkusb_get_device_handle(uint16_t vendor_id, uint16_t product_id, int sid) 
{
// Get open device handle with given vendor id, product id and serial id.
// Return first found device handle if sid == NK_SID_ANY.

  struct dev_open *curr = ldev_open;
  while (curr) {
    if (curr->vendor_id == vendor_id && curr->product_id == product_id) {
      if (sid == 0xFF)
        return curr->devh;
      else if (curr->serial_id == sid)
        return curr->devh;
    }

    curr = curr->next;
  }

  return 0;
}

int USB3Read(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t count, 
             uint32_t addr, unsigned char *data)
{
  const unsigned int timeout = 1000; 
  int length = 8;
  int transferred;
  unsigned char *buffer;
  int stat = 0;
  int nbulk;
  int remains;
  int loop;
  int size = 16384; // 16 kB

  nbulk = count / 4096;
  remains = count % 4096;

  if (!(buffer = (unsigned char *)malloc(size))) {
    fprintf(stderr, "USB3Read: Could not allocate memory (size = %d\n)", size);
    return -1;
  }
  
  buffer[0] = count & 0xFF;
  buffer[1] = (count >> 8)  & 0xFF;
  buffer[2] = (count >> 16)  & 0xFF;
  buffer[3] = (count >> 24)  & 0xFF;
  
  buffer[4] = addr & 0xFF;
  buffer[5] = (addr >> 8)  & 0xFF;
  buffer[6] = (addr >> 16)  & 0xFF;
  buffer[7] = (addr >> 24)  & 0x7F;
  buffer[7] = buffer[7] | 0x80;

  libusb_device_handle *devh = nkusb_get_device_handle(vendor_id, product_id, sid);
  if (!devh) {
    fprintf(stderr, "USB3Write: Could not get device handle for the device.\n");
    return -1;
  }

  if ((stat = libusb_bulk_transfer(devh, USB3_SF_WRITE, buffer, length, &transferred, timeout)) < 0) {
    fprintf(stderr, "USB3Read: Could not make write request; error = %d\n", stat);
    USB3Reset(vendor_id, product_id, sid);
    free(buffer);
    return stat;
  }

  for (loop = 0; loop < nbulk; loop++) {
    if ((stat = libusb_bulk_transfer(devh, USB3_SF_READ, buffer, size, &transferred, timeout)) < 0) {
      fprintf(stderr, "USB3Read: Could not make read request; error = %d\n", stat);
      USB3Reset(vendor_id, product_id, sid);
      return 1;
    }
    memcpy(data + loop * size, buffer, size);
  }

  if (remains) {
    if ((stat = libusb_bulk_transfer(devh, USB3_SF_READ, buffer, remains * 4, &transferred, timeout)) < 0) {
      fprintf(stderr, "USB3Read: Could not make read request; error = %d\n", stat);
      USB3Reset(vendor_id, product_id, sid);
      return 1;
    }
    memcpy(data + nbulk * size, buffer, remains * 4);
  }

  free(buffer);
  
  return 0;
}

int USB3ReadReg(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t addr)
{
  unsigned char data[4];
  unsigned int value;
  unsigned int tmp;

  USB3Read(vendor_id, product_id, sid, 1, addr, data);

  value = data[0] & 0xFF;
  tmp = data[1] & 0xFF;
  value = value + (unsigned int)(tmp << 8);
  tmp = data[2] & 0xFF;
  value = value + (unsigned int)(tmp << 16);
  tmp = data[3] & 0xFF;
  value = value + (unsigned int)(tmp << 24);

  return value;
}  

int USB3Write(uint16_t vendor_id, uint16_t product_id, unsigned char sid, uint32_t addr, uint32_t data)
{
  int transferred = 0;  
  const unsigned int timeout = 1000;
  int length = 8;
  unsigned char *buffer;
  int stat = 0;
  
  if (!(buffer = (unsigned char *)malloc(length))) {
    fprintf(stderr, "USB3Write: Could not allocate memory (size = %d\n)", length);
    return -1;
  }
  
  buffer[0] = data & 0xFF;
  buffer[1] = (data >> 8)  & 0xFF;
  buffer[2] = (data >> 16)  & 0xFF;
  buffer[3] = (data >> 24)  & 0xFF;
  
  buffer[4] = addr & 0xFF;
  buffer[5] = (addr >> 8)  & 0xFF;
  buffer[6] = (addr >> 16)  & 0xFF;
  buffer[7] = (addr >> 24)  & 0x7F;
  
  libusb_device_handle *devh = nkusb_get_device_handle(vendor_id, product_id, sid);
  if (!devh) {
    fprintf(stderr, "USB3Write: Could not get device handle for the device.\n");
    return -1;
  }
  
  if ((stat = libusb_bulk_transfer(devh, USB3_SF_WRITE, buffer, length, &transferred, timeout)) < 0) {
    fprintf(stderr, "USB3Write: Could not make write request; error = %d\n", stat);
    USB3Reset(vendor_id, product_id, sid);
    free(buffer);
    return stat;
  }
  
  free(buffer);

  usleep(1000);

  return stat;
}

int USB3Reset(uint16_t vendor_id, uint16_t product_id, unsigned char sid)
{
  const unsigned int timeout = 1000;
  unsigned char data;
  int stat = 0;
  
  libusb_device_handle *devh = nkusb_get_device_handle(vendor_id, product_id, sid);
  if (!devh) {
    fprintf(stderr, "USB3Write: Could not get device handle for the device.\n");
    return -1;
  }
  
  if ((stat = libusb_control_transfer(devh, LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_ENDPOINT_OUT, 
                                      0xD6, 0, 0, &data, 0, timeout)) < 0) {
    fprintf(stderr, "USB3WriteControl:  Could not make write request; error = %d\n", stat);
    return stat;
  }
  
  return stat;
}

// ******************************************************************************************************

// initialize libusb library
void UOSDAQ3init(libusb_context **ctx)
{
  if (libusb_init(ctx) < 0) {
    fprintf(stderr, "failed to initialise libusb\n");
    exit(1);
  }
}

// de-initialize libusb library
void UOSDAQ3exit(libusb_context *ctx)
{
  libusb_exit(ctx); 
}

// open UOSDAQ3
int UOSDAQ3open(int sid, libusb_context *ctx)
{
  struct libusb_device **devs;
  struct libusb_device *dev;
  struct libusb_device_handle *devh;
  size_t i = 0;
  int nopen_devices = 0; //number of open devices
  int r;
  int interface = 0;
  int sid_tmp;
  int speed;

  if (libusb_get_device_list(ctx, &devs) < 0) 
    fprintf(stderr, "Error: open_device: Could not get device list\n");

  fprintf(stdout, "Info: open_device: opening device Vendor ID = 0x%X, Product ID = 0x%X, Serial ID = %u\n",
                   UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid);

  while ((dev = devs[i++])) {
    struct libusb_device_descriptor desc;
    r = libusb_get_device_descriptor(dev, &desc);
    if (r < 0) {
      fprintf(stdout, "Warning, open_device: could not get device device descriptior." " Ignoring.\n");
      continue;
    }

    if (desc.idVendor == UOSDAQ3_VENDOR_ID && desc.idProduct == UOSDAQ3_PRODUCT_ID)  {
      r = libusb_open(dev, &devh);
      if (r < 0) {
        fprintf(stdout, "Warning, open_device: could not open device." " Ignoring.\n");
        continue;
      }

      // do not open twice
      if (is_device_open(devh)) {
        fprintf(stdout, "Info, open_device: device already open." " Ignoring.\n");
        libusb_close(devh);
        continue;
      }

      // See if sid matches
      // Assume interface 0
      if (libusb_claim_interface(devh, interface) < 0) {
        fprintf(stdout, "Warning, open_device: could not claim interface 0 on the device." " Ignoring.\n");
        libusb_close(devh);
        continue;
      }

      sid_tmp = get_serial_id(devh);

      if (sid == 0xFF || sid == sid_tmp) {
        add_device(&ldev_open, devh, UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid_tmp);
        nopen_devices++;
  
        // Print out the speed of just open device 
        speed = libusb_get_device_speed(dev);
        switch (speed) {
          case 4:
            fprintf(stdout, "Info: open_device: super speed device opened");
            break;
          case 3:
            fprintf(stdout, "Info: open_device: high speed device opened");
            break;
          case 2:
            fprintf(stdout, "Info: open_device: full speed device opened");
            break;
          case 1:
            fprintf(stdout, "Info: open_device: low speed device opened");
            break;
          case 0:
            fprintf(stdout, "Info: open_device: unknown speed device opened");
            break;
        }
        
        fprintf(stdout, " (bus = %d, address = %d, serial id = %u).\n",
                    libusb_get_bus_number(dev), libusb_get_device_address(dev), sid_tmp);
        libusb_release_interface(devh, interface);
        break;
      }
      else {
        libusb_release_interface(devh, interface);
        libusb_close(devh);
      }
    }
  }

  libusb_free_device_list(devs, 1);

  // claim interface
  handle_interface_id(&ldev_open, UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 0, kInterfaceClaim);

  if (!nopen_devices)
    return -1;

  devh = nkusb_get_device_handle(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid);
  if (!devh) {
    fprintf(stderr, "Could not get device handle for the device.\n");
    return -1;
  }

   return 0;
}

// close probecard
void UOSDAQ3close(int sid)
{
  int data_size;
  unsigned char data[16384];

  // read data until data buffer is empty
  data_size = UOSDAQ3read_DATASIZE(sid);

  while (data_size) {
    UOSDAQ3read_BUFFER(sid, data);
    data_size = UOSDAQ3read_DATASIZE(sid);
  }

  handle_interface_id(&ldev_open, UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 0, kInterfaceRelease);
  remove_device_id(&ldev_open, UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid);
}

// read data size
int UOSDAQ3read_DATASIZE(int sid)
{
  return USB3ReadReg(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 2);
}

// read data buffer
void UOSDAQ3read_BUFFER(int sid, unsigned char *data)
{
  USB3Read(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 4096, 0x1000, data);  
}

// read data
void UOSDAQ3read_DATA(int sid, unsigned char *data)
{
  int data_size;

  // wait for data buffer filled
  data_size = 0;
  while (!data_size)
    data_size = UOSDAQ3read_DATASIZE(sid);

  // read data buffer
  UOSDAQ3read_BUFFER(sid, data);
}

// get # of data size in 1 sec
// 1 data size has 32 frames and 1 frame time = 28.667 us * ADC decimation
int UOSDAQ3get_NUM(double sec, int dec)
{
  double period;
  double dval;
  int value;

  period = 32.0 * 28.667 * (double)(dec);
  dval = sec * 1000000.0 / period + 0.5;
  value = (int)(dval);

  return value;
}

// get ADC value
void UOSDAQ3get_DATA(unsigned char *data, int *adcX, int *adcY, int *frame)
{
  int i;

  for (i = 0; i < 100; i++) {
    adcX[i] = data[4 * i + 1] & 0x0F;
    adcX[i] = adcX[i] << 8;
    adcX[i] = adcX[i] + (data[4 * i] & 0xFF);

    adcY[i] = data[4 * i + 3] & 0x0F;
    adcY[i] = adcY[i] << 8;
    adcY[i] = adcY[i] + (data[4 * i + 2] & 0xFF);
  }

  *frame = data[1] & 0xF0;
  *frame = *frame + ((data[3] >> 4) & 0xF);
  *frame = *frame + (((data[5] >> 4) & 0xF) << 8);
  *frame = *frame + (((data[7] >> 4) & 0xF) << 12);
  *frame = *frame + (((data[9] >> 4) & 0xF) << 16);
  *frame = *frame + (((data[11] >> 4) & 0xF) << 20);
  *frame = *frame + (((data[13] >> 4) & 0xF) << 24);
  *frame = *frame + (((data[15] >> 4) & 0xF) << 28);
}

// reset data acquisition
void UOSDAQ3reset(int sid)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 0, 0);
}

// start data acquisition
void UOSDAQ3start_DAQ(int sid)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 1, 1);
}

// stop data acquisition
void UOSDAQ3stop_DAQ(int sid)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 1, 0);
}

// read DAQ status
// 0 = stopped, 1 = running
int UOSDAQ3read_RUN(int sid)
{
  return USB3ReadReg(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 1);
}

// write gain
// 0 = 5.2 nA, 1 = 10 nA, 2 = 20 nA, 3 = 48 nA,
// 4 = 96 nA, 5 = 192 nA, 6 = 288 nA, 7 = 384 nA
void UOSDAQ3write_GAIN(int sid, int data)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 3, data);
}

// read gain
int UOSDAQ3read_GAIN(int sid)
{
  return USB3ReadReg(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 3);
}

// write polarity
// 0 = negative current, 1 = positive current
void UOSDAQ3write_POL(int sid, int data)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 4, data);
}

// read polarity
int UOSDAQ3read_POL(int sid)
{
  return USB3ReadReg(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 4);
}

// write ADC decimation, 1/2/4/8/16
void UOSDAQ3write_DEC(int sid, int data)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 5, data);
}

// read ADC decimation
int UOSDAQ3read_DEC(int sid)
{
  return USB3ReadReg(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 5);
}

// write ADC input delay
void UOSDAQ3write_ADCDLY(int sid, int data)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 6, data);
}

// send ADC input delay calibration
void UOSDAQ3send_ADCCAL(int sid)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid, 7, 0);
}

// setup ADC
void UOSDAQ3setup_ADC(int sid, int addr, int data)
{
  USB3Write(UOSDAQ3_VENDOR_ID, UOSDAQ3_PRODUCT_ID, sid,  0x100 | addr, data);
}

// setup DAQ
// gain : 0 = 5.2 nA, 1 = 10 nA, 2 = 20 nA, 3 = 48 nA,
//        4 = 96 nA, 5 = 192 nA, 6 = 288 nA, 7 = 384 nA
// pol :  0 = negative current, 1 = positive current
// dec :  1/2/4/8/16
void UOSDAQ3setup_DAQ(int sid, int gain, int pol, int dec)
{
  // set ADC input delay
  UOSDAQ3write_ADCDLY(sid, 50);
  UOSDAQ3send_ADCCAL(sid);

  // setup ADC to normal operation
  UOSDAQ3setup_ADC(sid, 0x0D, 0x00);
  UOSDAQ3setup_ADC(sid, 0xFF, 0x01);

  // set gain, polarity and ADC decimation
  UOSDAQ3write_GAIN(sid, gain);
  UOSDAQ3write_POL(sid, pol);
  UOSDAQ3write_DEC(sid, dec);

  // readback settings
  printf("gain = %d\n", UOSDAQ3read_GAIN(sid));
  printf("polarity = %d\n", UOSDAQ3read_POL(sid));
  printf("ADC decimation = %d\n", UOSDAQ3read_DEC(sid));
}





