/*
 Library written for use with Common-Anode 7-Segment Display. For more information on how to use this library,
 please refer to the github README.
 Written by: Derek Duncan
 Data: 4/7/2018
*/

#include "Arduino.h"
#include "MCP4131.h"
#include <SPI.h>

MCP4131::MCP4131(int slave_select_pin) {
    SPI.begin();
    
	pinMode(slave_select_pin, OUTPUT);
}

MCP4131::readWiper() {
    SPI.beginTransaction(settingsA);
    Serial.println("Entered Read");
    // take the SS pin low to select the chip:
    digitalWrite(slaveSelectPin, LOW);
    //  send in the address and value via SPI:
    byte error = SPI.transfer(0x0F);
    byte result = SPI.transfer(0xFF);
    //unsigned int result = SPI.transfer(0xC);
    // take the SS pin high to de-select the chip:
    digitalWrite(slaveSelectPin, HIGH);
    SPI.endTransaction();
    Serial.println(error);
    Serial.println(result);
    
}

MCP4131::checkIfError(byte error_byte) {

	boolean error_bool = (error_byte & error_mask) << 1;

	return error_bool;
}
