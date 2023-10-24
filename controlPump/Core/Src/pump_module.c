/*
 * pump_module.c
 *
 *  Created on: Oct 9, 2023
 *      Author: buiqb
 */

#include "pump_module.h"
#include "main.h"

static state_m stateMachine;
static uint32_t timePass;

void state_Machine_Update(void);
void init_State(){
	stateMachine = S_0;
}
void stateUpdate(){
	switch (stateMachine){
		case S_0:
			if (!(LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_1))){
				stateMachine = S_1;
				timePass = getTime();
			}
			break;
		case S_1:
			if((getTime()-timePass) >= 1500){
				stateMachine = S_2;
				LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0);
				timePass = getTime();
			}else{
				if(LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_1)){
					stateMachine = S_0;
				}
			}
			break;
		case S_2:
			if (!(LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_1))){
				stateMachine = S_3;
				timePass = getTime();
			}
			break;
		case S_3:
			if((getTime()-timePass) >= 3000){
				stateMachine = S_0;
				LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);
				timePass = getTime();
			}else{
				if(LL_GPIO_IsInputPinSet(GPIOA,LL_GPIO_PIN_1)){
					stateMachine = S_2;
				}
			}
			break;
	}
}
