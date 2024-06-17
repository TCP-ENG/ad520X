#include "ad520x.h"
#include <Arduino.h>
#include "SPI.h"

void setAD5204(uint8_t cs, uint8_t chan, uint8_t value)
{
    digitalWrite(cs,LOW);
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    SPI.transfer(chan);
    SPI.transfer(value);
    SPI.endTransaction();
    digitalWrite(cs,HIGH);
}

void setAD5204(uint8_t cs, uint16_t data)
{
    ad520xPKT pkt;
    pkt.d16 = data;
    setAD5204(cs,pkt.b.channel,pkt.b.value);
}