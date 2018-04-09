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
        void writeWiper();

     // SegmentDisplay(int pin1, int pin2, int pin4, int pin5, int pin6, int pin7, int pin9, int pin10);
     // void displayDecimalPoint();
     // void displayHex(int numberToDisplay, boolean decimalPointFlag);
     // void testDisplay();
      // Not ready
	  // void displaySaver();

    private:
        byte error_mask = 0x02;
<<<<<<< HEAD
        boolean checkIfError(byte errorByte);
=======
        boolean checkIfError(byte error_byte);
>>>>>>> c4862213d728604b5b04cfc44df1e49596d61e81
};

#endif
