/*
 * input_reading.c
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */

#include "main.h"
# define NO_OF_BUTTONS 					3

#define DURATION_FOR_HOLD				10
#define DURATION_FOR_AUTO_INCREASING 	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint8_t flagForButtonHeld[NO_OF_BUTTONS];

static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonHeld[NO_OF_BUTTONS];
static uint16_t BUTTON_Pin[3] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};
void initButton(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;

		buttonBuffer[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		counterForButtonPress1s[i] = 0;
	}
}

void button_reading(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer3[i];
		debounceButtonBuffer3[i] = HAL_GPIO_ReadPin(GPIOB, BUTTON_Pin[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i] && debounceButtonBuffer2[i] == debounceButtonBuffer3[i]){
			buttonBuffer[i] = debounceButtonBuffer3[i];
		}
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress1s[i]++;
			}
			else{
				flagForButtonPress1s[i] = 1;

				if(counterForButtonHeld[i] < DURATION_FOR_HOLD){
					counterForButtonHeld[i]++;
					if(counterForButtonHeld[i] >= DURATION_FOR_HOLD){
						flagForButtonHeld[i] = 1;
						counterForButtonHeld[i] = 0;
					}
				}

			}
		}
		else{
			counterForButtonPress1s[i] = 0;
			counterForButtonHeld[i] = 0;
			flagForButtonPress1s[i] = 0;
			flagForButtonHeld[i] = 0;
		}
	}
}

unsigned char is_button_pressed(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}

unsigned char is_button_held(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return flagForButtonHeld[index] == 1;
}
void reset_flagForButtonHeld(unsigned char index){
	if(index >= NO_OF_BUTTONS) return;
	flagForButtonHeld[index] = 0;
}









