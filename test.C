
#include <stdio.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>
#include "src/NoticeUOSDAQ3.h"
#include <time.h>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

void test(){
  double sec;
  int nread, nsample;
  unsigned char data[16384];
  int adcX[100];
  int adcY[100];
  int i;
  int frame;
  int count=0;
  int sid = 1;
  sec = 1;
  int gain = 0;
  int pol = 0;
  int dec = 1;

  // open USB3
  UOSDAQ3init(0);
  // open UOSDAQ3  
  UOSDAQ3open(sid, 0);
  // write settings
  UOSDAQ3setup_DAQ(sid, gain, pol, dec);
  // get # of frames to take
  // 32 frames per read
  nread = UOSDAQ3get_NUM(0.01, dec);
  //nread=100;
  nsample = 0*nread * 32;
  // reset DAQ
  UOSDAQ3reset(sid);
  // start DAQ by software
  UOSDAQ3start_DAQ(sid);


    UOSDAQ3read_DATA(sid, data);
      unsigned char *evdata = &(data[0*512]);
      UOSDAQ3get_DATA(evdata, adcX, adcY, &frame);



  //nread=10000;
 /*### 
  cout<<"runing..."<<endl;
    
    // reads 16384 char at once
    // each 'event' is 512 char
    UOSDAQ3read_DATA(sid, data);
    // reads 32 events at once
    //printf("nread:: %i \n", i);
    for (int event =0; event < 32; ++event) {
      unsigned char *evdata = &(data[event*512]);
      UOSDAQ3get_DATA(evdata, adcX, adcY, &frame);
      // std::cout <<"evdata:: "<< evdata<<std::endl;
      // for (int cc=0; cc<512; ++cc) {
      //   std::cout << std::bitset<4>(evdata[cc]);
      // }
      
      //printf("frame:: %i \n", frame);
    nsample +=1;
      //Fill histogram

    break;
    }

  // normalising pedestals

  ###*/ 
  UOSDAQ3stop_DAQ(sid);
  UOSDAQ3close(sid);
  UOSDAQ3exit(0);
}
