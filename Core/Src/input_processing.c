/*
 * input_processing.c
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */


#include "input_processing.h"



enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

static void increaseNewValue(){
	switch (mode) {
		case 2:
			redNew++;
			if(redNew > 99) redNew = 1;
			break;
		case 3:
			amberNew++;
			if(amberNew > 99) amberNew = 1;
			break;
		case 4:
			greenNew++;
			if(greenNew > 99) greenNew = 1;
			break;
		default:
			break;
	}
}
static void setNewDuration(){
	int diff = 0;
	switch (mode) {
		case 2:
			diff = redNew - redValue;
			redValue = redNew;
			greenValue += diff;
			greenNew += diff;
			break;
		case 3:
			diff = amberNew - amberValue;
			amberValue = amberNew;
			redValue += diff;
			redNew += diff;
			break;
		case 4:
			diff = greenNew - greenValue;
			greenValue = greenNew;
			redValue += diff;
			redNew += diff;
			break;
		default:
			break;
	}
}

void fsm_for_input_processing(void){
	switch (buttonState[0]) {
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState[0] = BUTTON_PRESSED;
				mode++;
				if(mode == 2 || mode == 3 || mode == 4){
					initColor1();
					initColor2();
				}
				if(mode > 4) {
					mode = 1;
					resetCountValue();
				}
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(0)){
				buttonState[0] = BUTTON_RELEASED;
			}
			if(is_button_pressed_1s(0)){
				buttonState[0] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				mode++;
				if(mode == 2 || mode == 3 || mode == 4){
					initColor1();
					initColor2();
				}
				if(mode > 4) {
					mode = 1;
					resetCountValue();
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(0)){
				buttonState[0] = BUTTON_RELEASED;
			}
			if(is_button_held(0)){
				mode++;
				if(mode == 2 || mode == 3 || mode == 4){
					initColor1();
					initColor2();
				}
				if(mode > 4) {
					mode = 1;
					resetCountValue();
				}
				reset_flagForButtonHeld(0);
			}
			break;
		default:
			break;
	}

	switch (buttonState[1]) {
		case BUTTON_RELEASED:
			if(is_button_pressed(1)){
				buttonState[1] = BUTTON_PRESSED;
				increaseNewValue();
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(1)){
				buttonState[1] = BUTTON_RELEASED;
			}
			if(is_button_pressed_1s(1)){
				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				increaseNewValue();
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(1)){
				buttonState[1] = BUTTON_RELEASED;
			}
			if(is_button_held(1)){
				increaseNewValue();
				reset_flagForButtonHeld(1);
			}
			break;
		default:
			break;
	}

	switch (buttonState[2]) {
		case BUTTON_RELEASED:
			if(is_button_pressed(2)){
				setNewDuration();
				buttonState[2] = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(2)){
				buttonState[2] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}

void fsm_automatic_run(){
//	if(timer_flag[1] == 1){
//		ledScanning();
//		setTimer(1, 10);
//	}
//	ledDispMode();
}


