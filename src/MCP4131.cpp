/*
 Library written for use with Common-Anode 7-Segment Display. For more information on how to use this library,
 please refer to the github README.
 Written by: Derek Duncan
 Data: 2/4/2016
*/

#include "Arduino.h"
#include "SegmentDisplay.h"

MCP4131::MCP4131(int slave_select_pin) {
	pinMode(slave_select_pin, OUTPUT);
}