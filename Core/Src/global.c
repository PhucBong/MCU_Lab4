/*
 * global.c
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */

#include "global.h"

int mode = 1;
int redValue, amberValue, greenValue;
int redNew, amberNew, greenNew;

void initLedTime(){
	redValue = RED_INIT;
	amberValue = AMBER_INIT;
	greenValue = GREEN_INIT;
	redNew = redValue;
	amberNew = amberValue;
	greenNew = greenValue;
}

