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
}

byte MCP4131::readWiper() {
    // Adjust SPI settings to fit MCP4131
    SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
    
    // take the SS pin low to select the chip:
    enableChip();
    
    // Send the MSB of the 16bit read command to receive CMDR bit to check
    byte error = SPI.transfer(0x0F);

    //if(checkIfError(error))
    //    return;
        
    // Send LSB to retrieve the value of the Wiper
    byte result = SPI.transfer(0xFF);
    
    // take the SS pin high to de-select the chip:
    disableChip();
    SPI.endTransaction();
    
    Serial.println(error);
    Serial.println(result);
    
    return result;
}

byte MCP4131::writeWiper() {
    // Adjust SPI settings to fit MCP4131
    SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
    
    // take the SS pin low to select the chip:
    enableChip();
    
    // Send the MSB of the 16bit read command to receive CMDR bit to check
    byte error = SPI.transfer(0x0F);

    //if(checkIfError(error))
    //    return;
        
    // Send LSB to retrieve the value of the Wiper
    byte result = SPI.transfer(0xFF);
    
    // take the SS pin high to de-select the chip:
    disableChip();
    SPI.endTransaction();
    
    Serial.println(error);
    Serial.println(result);
    
    return result;
}

void MCP4131::sendCommand(/*byte address, byte command, byte data*/) {
    // Adjust SPI settings to fit MCP4131
    SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
    
    // take the SS pin low to select the chip:
    enableChip();
    
    //byte msb = ((address & address_mask) << 4) | ((command & command_mask) << 2);
	byte buf[4];
	buf[0] = 0x0;
	buf[1] = 0x3;
	buf[2] = 0xF;
	buf[3] = 0xF;
	SPI.transfer(buf, 4);
    
    //byte error = SPI.transfer(0x0F);
    
}

void MCP4131::enableChip() {
    digitalWrite(slaveSelectPin, LOW);
}

void MCP4131::disableChip() {
    digitalWrite(slaveSelectPin, HIGH);
}

boolean MCP4131::checkIfError(byte errorByte) {
    boolean errorBoolean = (errorByte & 0x02) >> 1;
    return !errorBoolean;
}
