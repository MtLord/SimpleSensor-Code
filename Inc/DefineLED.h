/*
 * DefineLED.h
 *
 *  Created on: 2019/08/27
 *      Author: —T‘¿
 */

#ifndef DEFINELED_H_
#define DEFINELED_H_

#define TOGGLE_TX_LED HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
#define TOGGLE_RX_LED  HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
#define SET_ERROR_LED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
#define RESET_ERRORLED HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);



#endif /* DEFINELED_H_ */
