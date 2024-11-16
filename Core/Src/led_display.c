/*
 * led_display.c
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */
#include "led_display.h"


enum Color {RED, AMBER, GREEN};

void initColor1(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}
void setRed1(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}
void setAmber1(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}
void setGreen1(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
}


void initColor2(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void setRed2(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void setAmber2(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void setGreen2(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}

void display7SEG(int index){
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, SET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		default:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
	}
}

void init7SEG(void){
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, SET);
	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
}

void toggleRed(){
	HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
	HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void toggleAmber(){
	HAL_GPIO_TogglePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin);
	HAL_GPIO_TogglePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void toggleGreen(){
	HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
	HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, SET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, SET);
}
int cnt1 = RED_INIT;
int cnt2 = GREEN_INIT;
int redValue = RED_INIT;
int greenValue = GREEN_INIT;
int amberValue = AMBER_INIT;
int redNew = RED_INIT;
int greenNew = GREEN_INIT;
int amberNew = AMBER_INIT;
enum Color state1 = RED;
enum Color state2 = GREEN;



void resetCountValue(){
	cnt1 = redValue;
	cnt2 = greenValue;
	state1 = RED;
	state2 = GREEN;
}

void normalMode(){
	cnt1--;
	cnt2--;
	switch (state1) {
		case RED:
			setRed1();
			if(cnt1 <= 0){
				cnt1 = greenValue;
				//cnt1 = 20;
				state1 = GREEN;
			}
			break;
		case AMBER:
			setAmber1();
			if(cnt1 <= 0){
				cnt1 = redValue;
				//cnt1 = 25;
				state1 = RED;
			}
			break;
		case GREEN:
			setGreen1();
			if(cnt1 <= 0){
				cnt1 = amberValue;
				//cnt1 = 5;
				state1 = AMBER;
			}
			break;
		default:
			break;
	}
	switch (state2) {
		case RED:
			setRed2();
			if(cnt2 <= 0){
				cnt2 = greenValue;
				//cnt2 = 20;
				state2 = GREEN;
			}
			break;
		case AMBER:
			setAmber2();
			if(cnt2 <= 0){
				cnt2 = redValue;
				//cnt2 = 25;
				state2 = RED;
			}
			break;
		case GREEN:
			setGreen2();
			if(cnt2 <= 0){
				cnt2 = amberValue;
				//cnt2 = 5;
				state2 = AMBER;
			}
			break;
		default:
			break;
	}
}

int get7SEG1Value(){
	switch (mode) {
		case 1:
			return cnt1;
			break;
		case 2:
			return redNew;
			break;
		case 3:
			return amberNew;
			break;
		case 4:
			return greenNew;
			break;
		default:
			break;
	}
	return 0;
}
int get7SEG2Value(){
	switch (mode) {
		case 1:
			return cnt2;
			break;
		case 2:
			return redNew;
			break;
		case 3:
			return amberNew;
			break;
		case 4:
			return greenNew;
			break;
		default:
			break;
	}
	return 0;
}

void ledDispMode(){
	switch (mode) {
		case 1:
			;
			break;
		case 2:
			toggleRed();
			break;
		case 3:
			toggleAmber();
			break;
		case 4:
			toggleGreen();
			break;
		default:
			break;
	}
}

void ledScanning(){
	static int sw_led = 0;
	switch (sw_led) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, RESET);
			display7SEG(get7SEG1Value() / 10);
			sw_led = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, RESET);
			display7SEG(get7SEG1Value() % 10);
			sw_led = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, RESET);
			display7SEG(get7SEG2Value() / 10);
			sw_led = 3;
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, RESET);
			display7SEG(get7SEG2Value() % 10);
			sw_led = 4;
			break;
		case 4:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, SET);
			display7SEG(mode);
			sw_led = 0;
			break;
		default:
			break;
	}
}




