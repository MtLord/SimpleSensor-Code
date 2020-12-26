/*
 * MicroSW.hpp
 *
 *  Created on: 2019/05/14
 *      Author: �T��
 */

#ifndef MICROSW_MICROSW_HPP_
#define MICROSW_MICROSW_HPP_
#include "CAN/CAN.hpp"
#include "stm32f3xx_hal.h"
class MicroSw
{
	GPIO_TypeDef *GPIOx;
	unsigned short pin;
public:
	MicroSw(GPIO_TypeDef *_GPIOx,unsigned short _pin):GPIOx(_GPIOx),pin(_pin)
	{

	}
	short GetPush();
};







#endif /* MICROSW_MICROSW_HPP_ */
