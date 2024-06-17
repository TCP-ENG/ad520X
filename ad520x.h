#ifndef _AD520X_H_
#define _AD520X_H_
#include <Arduino.h>

#define PACKED __attribute__ ((packed))
typedef union
{
    uint16_t d16;
    /* data */
    struct 
    {
        uint8_t channel;
        uint8_t value;  
    } b;
}ad520xPKT;




void setAD5204(uint8_t cs, uint8_t chan, uint8_t value);
void setAD5204(uint8_t cs, uint16_t data);


#endif
