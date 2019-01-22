/*
 
 
 Written by: Derek Duncan
 Data: 04/03/2018
 */

#ifndef MCP4131_H
#define MCP4131_H

#include "Arduino.h"

class MCP4131
{
    public:
        MCP4131(int slave_select_pin);
        byte readWiper();
        byte writeWiper();
		void sendCommand(/*byte address, byte command, byte data*/);


     // SegmentDisplay(int pin1, int pin2, int pin4, int pin5, int pin6, int pin7, int pin9, int pin10);
     // void displayDecimalPoint();
     // void displayHex(int numberToDisplay, boolean decimalPointFlag);
     // void testDisplay();
      // Not ready
	  // void displaySaver();

    private:
        const static byte error_mask = 0x02;
        const static byte address_wiper = 0x0;
    
        const static unsigned char command_write = B00;
        const static unsigned char command_read = B11;
        const static unsigned char command_increment = B01;
        const static unsigned char command_decrement = B10;
    
        boolean checkIfError(byte errorByte);
        void enableChip();
        void disableChip();
    

};

#endif
