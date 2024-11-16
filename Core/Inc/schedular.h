/*
 * schedular.h
 *
 *  Created on: Nov 15, 2024
 *      Author: truon
 */

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#define SCH_MAX_TASKS 	40
#define NO_TASK_ID 		0

#define RETURN_ERROR 	0
#define RETURN_NORMAL 	1

#define ERROR_NONE 						0
#define ERROR_SCH_TOO_MANY_TASKS 		1
#define ERROR_SCH_CANNOT_DELETE_TASK	2

#include <stdint.h>

typedef struct{
	void (*pTask) (void);
	uint32_t Period;
	uint32_t Delay;
	uint8_t RunMe;

	uint32_t TaskID;
} sTasks;

void SCH_INIT(void);
uint32_t SCH_ADD_TASK(void (*pFunction)(), uint32_t Delay, uint32_t Period);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
void SCH_Delete(uint32_t TaskID);
void SCH_Delete_Special(void (*funcPtr)());
int SCH_Check_Task(void (*funcPtr)());

void Timer_init();
void Watchdog_init();
void SCH_Report_Status();
void SCH_Go_To_Sleep();
#endif /* INC_SCHEDULAR_H_ */
