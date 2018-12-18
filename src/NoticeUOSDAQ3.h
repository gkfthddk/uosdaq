#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UOSDAQ3_VENDOR_ID  (0x0547)
#define UOSDAQ3_PRODUCT_ID (0x1706)

#define USB3_SF_READ   (0x82)
#define USB3_SF_WRITE  (0x06)

extern void UOSDAQ3init(libusb_context **ctx);
extern void UOSDAQ3exit(libusb_context *ctx);
extern int UOSDAQ3open(int sid, libusb_context *ctx);
extern void UOSDAQ3close(int sid);
extern int UOSDAQ3read_DATASIZE(int sid);
extern void UOSDAQ3read_BUFFER(int sid, unsigned char *data);
extern void UOSDAQ3read_DATA(int sid, unsigned char *data);
extern int UOSDAQ3get_NUM(double sec, int dec);
extern void UOSDAQ3get_DATA(unsigned char *data, int *adcX, int *adcY, int *frame);
extern void UOSDAQ3reset(int sid);
extern void UOSDAQ3start_DAQ(int sid);
extern void UOSDAQ3stop_DAQ(int sid);
extern int UOSDAQ3read_RUN(int sid);
extern void UOSDAQ3write_GAIN(int sid, int data);
extern int UOSDAQ3read_GAIN(int sid);
extern void UOSDAQ3write_POL(int sid, int data);
extern int UOSDAQ3read_POL(int sid);
extern void UOSDAQ3write_DEC(int sid, int data);
extern int UOSDAQ3read_DEC(int sid);
extern void UOSDAQ3write_ADCDLY(int sid, int data);
extern void UOSDAQ3send_ADCCAL(int sid);
extern void UOSDAQ3setup_ADC(int sid, int addr, int data);
extern void UOSDAQ3setup_DAQ(int sid, int gain, int pol, int dec);

#ifdef __cplusplus
}
#endif

