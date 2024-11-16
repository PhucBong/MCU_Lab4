/*
 * schedular.c
 *
 *  Created on: Oct 30, 2024
 *      Author: truon
 */
#include "schedular.h"
#include "main.h"

sTasks SCH_Task_G[SCH_MAX_TASKS];

uint32_t Error_code_G;
uint32_t current_index = 0;
void Timer_init(){

}
void Watchdog_init(){

}
void SCH_Report_Status(){

}
void SCH_Go_To_Sleep(){

}

void SCH_INIT(){
	uint32_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Task_G[i].pTask = 0x0000;
		SCH_Task_G[i].Period = 0;
		SCH_Task_G[i].Delay = 0;
		SCH_Task_G[i].RunMe = 0;
		SCH_Task_G[i].TaskID = i;
	}
//	Error_code_G = ERROR_NONE;
//	Timer_init();
//	Watchdog_init();
}
uint32_t SCH_ADD_TASK(void (*pFunction)(), uint32_t Delay, uint32_t Period){

	if(current_index < SCH_MAX_TASKS){
		SCH_Task_G[current_index].pTask = pFunction;
		SCH_Task_G[current_index].Delay = Delay / 10;
		SCH_Task_G[current_index].Period = Period / 10;
		SCH_Task_G[current_index].RunMe = 0;
		SCH_Task_G[current_index].TaskID = current_index;

		uint32_t j = 0, i = current_index;
		while(SCH_Task_G[j].Delay < SCH_Task_G[i].Delay){
			SCH_Task_G[i].Delay -= SCH_Task_G[j].Delay;
			j++;
		}
		if(j != current_index){
			SCH_Task_G[j].Delay -= SCH_Task_G[current_index].Delay;
			sTasks tmp = SCH_Task_G[current_index];
			// dich phai
			uint32_t u;
			for(u = current_index; u > 0; u--){
				SCH_Task_G[u] = SCH_Task_G[u - 1];
			}
			SCH_Task_G[j] = tmp;
		}
		current_index++;
	}
	return 1;
}
void SCH_Update(){
	if(SCH_Task_G[0].pTask){
		if(SCH_Task_G[0].Delay <= 0){
			SCH_Task_G[0].RunMe += 1;
			if(SCH_Task_G[0].Period != 0){
				SCH_Task_G[0].Delay = SCH_Task_G[0].Period;
			}
		}
		else{
			SCH_Task_G[0].Delay -= 1;
		}
	}
}
void SCH_Dispatch_Task(){
	uint32_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_Task_G[i].RunMe > 0){
			SCH_Task_G[i].RunMe--;
			(*SCH_Task_G[i].pTask)();
			if (SCH_Task_G[i].Period == 0){
				SCH_Delete(i);
			}
			else{
				// arrange lai
				uint32_t j;
				for(j = 0; j < SCH_MAX_TASKS; j++){
					if(i == j) continue;

					while(SCH_Task_G[j].Delay == 0 && SCH_Task_G[j].pTask){
						j++;
					}
					if(SCH_Task_G[j].pTask && SCH_Task_G[i].Delay <= SCH_Task_G[j].Delay){
						SCH_Task_G[j].Delay -= SCH_Task_G[i].Delay;
						// can phai swap neu j < i
						if(j < i){
							sTasks tmp = SCH_Task_G[i];
							SCH_Task_G[i] = SCH_Task_G[j];
							SCH_Task_G[j] = tmp;
						}
						break;
					}
					else{
						while(SCH_Task_G[j].pTask && SCH_Task_G[i].Delay > SCH_Task_G[j].Delay){

							SCH_Task_G[i].Delay -= SCH_Task_G[j].Delay;
							//chi swap neu nhu j > i
							if(j > i){
								sTasks tmp = SCH_Task_G[i];
								SCH_Task_G[i] = SCH_Task_G[j];
								SCH_Task_G[j] = tmp;
								i++;
							}
							j++;
							if(i == j) j++;
						}
						if(SCH_Task_G[j].pTask && SCH_Task_G[i].Delay <= SCH_Task_G[j].Delay){
							SCH_Task_G[j].Delay -= SCH_Task_G[i].Delay;
						}
						break;
					}

				}
			}
		}
	}
	//SCH_Report_Status();
	//SCH_Go_To_Sleep();
}

void SCH_Delete(uint32_t TaskID){
	SCH_Task_G[TaskID].pTask = 0x0000;
	SCH_Task_G[TaskID].Period = 0;
	SCH_Task_G[TaskID].Delay = 0;
	SCH_Task_G[TaskID].RunMe = 0;
	SCH_Task_G[TaskID].TaskID = 0;



	uint32_t i;
	// dich trai cai phan tu
	for(i = TaskID; i < SCH_MAX_TASKS - 1; i++){
		if(SCH_Task_G[i + 1].pTask){
			SCH_Task_G[i] = SCH_Task_G[i + 1];
		}
		else{
			SCH_Task_G[i].pTask = 0x0000;
			SCH_Task_G[i].Period = 0;
			SCH_Task_G[i].Delay = 0;
			SCH_Task_G[i].RunMe = 0;
			SCH_Task_G[i].TaskID = 0;

			break;
		}
	}
}
void SCH_Delete_Special(void (*funcPtr)()){
	uint32_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_Task_G[i].pTask == funcPtr){
			SCH_Delete(i);
			break;
		}
	}
}
int SCH_Check_Task(void (*funcPtr)()){
	uint32_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_Task_G[i].pTask == funcPtr) return 1;
	}
	return 0;
}
