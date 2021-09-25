/*
 * Button_STM32.c
 *
 *  Created on: 2021/09/25
 */

#include "main.h"
#include "Button_STM32.h"

#define MAX_BUTTONS 10
#define ButtonTime 10 // in msec

enum Button_State_Value Button_State[MAX_BUTTONS] = { BUTTON_INIT };

struct Button_buffer_struct {
	int prev_time;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
} Button_buffer[MAX_BUTTONS];

int Button_Init(int i, GPIO_TypeDef *G, uint16_t P) {
	Button_buffer[i].GPIOx = G;
	Button_buffer[i].GPIO_Pin = P;
	Button_State[i] = BUTTON_INIT;
}

int Button_Loop(int i) {

	if (HAL_GPIO_ReadPin(Button_buffer[i].GPIOx, Button_buffer[i].GPIO_Pin))
			{
		// release?
		switch (Button_State[i]) {
		case BUTTON_PRESSING:
			Button_State[i] = BUTTON_RELEASED;
			Button_buffer[i].prev_time = HAL_GetTick();
			break;
		case BUTTON_RELEASED:
			if ((HAL_GetTick() - Button_buffer[i].prev_time) > ButtonTime) {
				Button_State[i] = BUTTON_CLICKED;
			}
			break;
		default:
			break;
		}
	} else {
		// push?
		switch (Button_State[i]) {
		case BUTTON_INIT:
			Button_State[i] = BUTTON_PRESSED;
			Button_buffer[i].prev_time = HAL_GetTick();
			break;
		case BUTTON_PRESSED:
			if ((HAL_GetTick() - Button_buffer[i].prev_time) > ButtonTime) {
				Button_State[i] = BUTTON_PRESSING;
			}
			break;
		case BUTTON_CLICKED:
			Button_State[i] = BUTTON_INIT;
			break;
		default:
			break;
		}
	}
	return Button_State[i];
}
