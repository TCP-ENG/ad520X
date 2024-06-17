#include <Arduino.h>
#include "SPI.h"
#include "ad520x.h"

uint8_t cs = 7;
int chan = 0;
uint8_t value[4] = {127,127,127,127};

void setup() {
  SerialUSB.begin(115200);
  if(!SerialUSB.available())
  {
    ;
  }
  SerialUSB.read();
  pinMode(cs, OUTPUT);
  SPI.begin();
  setAD5204(cs,chan,value[chan]);
  SerialUSB.printf("Writing AD520X channel : %d  value : %d \r\n",chan,value[chan]);

}

void loop() {
  
  while (SerialUSB.available() > 0)
  {
    char c = SerialUSB.read();
    switch (c)
    {
    case 'u':
      value[chan]++;
      setAD5204(cs,chan,value[chan]);
      SerialUSB.printf("Writing AD520X channel : %d  value : %d \r\n",chan,value[chan]);
      break;
    
    case 'd':
      value[chan]--;
      setAD5204(cs,chan,value[chan]);
      SerialUSB.printf("Writing AD520X channel : %d  value : %d \r\n",chan,value[chan]);
      break;

    case 'c':
      chan++;
      if(chan >= 4)
      {
        chan = 0;
      }

    default:
      break;
    }
  }
}

