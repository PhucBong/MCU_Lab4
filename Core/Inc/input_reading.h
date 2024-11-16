/*
 * input_reading.h
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_


void initButton();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
unsigned char is_button_held(unsigned char index);
void reset_flagForButtonHeld(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
