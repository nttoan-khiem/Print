/*
 * pump_module.h
 *
 *  Created on: Oct 9, 2023
 *      Author: buiqb
 */

#ifndef PUMP_MODULE_H_
#define PUMP_MODULE_H_

typedef enum {S_0,S_1,S_2,S_3} state_m;
void init_State(void);
void stateUpdate(void);
#endif /* PUMP_MODULE_H_ */
