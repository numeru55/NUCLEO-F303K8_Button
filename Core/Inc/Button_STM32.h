/*
 * Button_STM32.h
 *
 *  Created on: 2021/09/25
 */

#ifndef INC_BUTTON_STM32_H_
#define INC_BUTTON_STM32_H_

enum Button_State_Value {
	BUTTON_INIT,
	BUTTON_PRESSED,
	BUTTON_PRESSING,
	BUTTON_RELEASED,
	BUTTON_CLICKED
};

int Button_Init(int i, GPIO_TypeDef *G, uint16_t P);
int Button_Loop(int i);

#endif /* INC_BUTTON_STM32_H_ */
