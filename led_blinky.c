/*
 * led_blinky.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LUUVINHLOI
 */

#include "led_blinky.h"

void led_blinky()
{
	switch(status) {
	case INIT:
		status = TurnOnLed;
		setTimer2(100);
		break;

	case TurnOnLed:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);

		if(timer2_flag == 1) {
			status = TurnOffLed;
			setTimer2(100);
		}
		break;

	case TurnOffLed:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);

		if(timer2_flag == 1) {
			status = TurnOnLed;
			setTimer2(100);
		}
		break;
	}

}
