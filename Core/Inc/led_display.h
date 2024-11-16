/*
 * led_display.h
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "global.h"
#include "schedular.h"


void initColor1(void);
void initColor2(void);
void setRed1(void);
void setRed2(void);
void setAmber1(void);
void setAmber2(void);
void setGreen1(void);
void setGreen2(void);

void init7SEG(void);
void display7SEG(int index);

void resetCountValue();
void ledDispMode();
void ledScanning();

int get7SEG1Value();
int get7SEG2Value();
void normalMode();
void resetCountValue();

#endif /* INC_LED_DISPLAY_H_ */
