/*
 Library written for use with Common-Anode 7-Segment Display. For more information on how to use this library,
 please refer to the github README.
 Written by: Derek Duncan
 Data: 4/7/2018
*/

#include "Arduino.h"
#include "MCP4131.h"
#include <SPI.h>

int slaveSelectPin;

MCP4131::MCP4131(int slavePin) {
    SPI.begin();
    slaveSelectPin = slavePin;
	pinMode(slavePin, OUTPUT);
<<<<<<< HEAD
}

boolean MCP4131::checkIfError(byte errorByte) {
    boolean errorBoolean = (errorByte & 0x02) >> 1;
    return !errorBoolean;
=======
>>>>>>> c4862213d728604b5b04cfc44df1e49596d61e81
}

byte MCP4131::readWiper() {
    SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
    // take the SS pin low to select the chip:
    digitalWrite(slaveSelectPin, LOW);
    //  send in the address and value via SPI:
    byte error = SPI.transfer(0x0F);
<<<<<<< HEAD
    Serial.println(checkIfError(error));
=======
    checkIfError(error);
>>>>>>> c4862213d728604b5b04cfc44df1e49596d61e81
    byte result = SPI.transfer(0xFF);
    //unsigned int result = SPI.transfer(0xC);
    // take the SS pin high to de-select the chip:
    digitalWrite(slaveSelectPin, HIGH);
    SPI.endTransaction();
    Serial.println(error);
    Serial.println(result);
    
    return result;
}

<<<<<<< HEAD

=======
boolean checkIfError(byte errorByte) {
    boolean errorBoolean = (errorByte & 0x02) >> 1;
    Serial.println(errorBoolean);
    
}
>>>>>>> c4862213d728604b5b04cfc44df1e49596d61e81
