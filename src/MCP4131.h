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
        void writeWiper(unsigned int wiperValue);
        void decrementWiper();
        void incrementWiper();

    private:
        const static byte ADDRESS_WIPER0 = 0x0;
        const static byte ADDRESS_WIPER1 = 0x1;
        const static byte COMMAND_MASK = 0x00;
    
        const static unsigned char COMMAND_WRITE = B00;
        const static unsigned char COMMAND_READ = B11;
        const static unsigned char COMMAND_INCREMENT = B01;
        const static unsigned char COMMAND_DECREMENT = B10;
    
        boolean checkIfError(byte errorByte);
        void enableChip();
        void disableChip();
        byte sendCommand(byte address, char command, unsigned int data);
        void sendCommand(byte address, char command);
};

#endif
