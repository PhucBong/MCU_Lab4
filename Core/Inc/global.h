/*
 * global.h
 *
 *  Created on: Oct 13, 2024
 *      Author: truon
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define RED_INIT 		30
#define AMBER_INIT		5
#define GREEN_INIT 		25

void initLedTime();
extern int mode;
extern int redValue, amberValue, greenValue;
extern int redNew, amberNew, greenNew;


#endif /* INC_GLOBAL_H_ */
