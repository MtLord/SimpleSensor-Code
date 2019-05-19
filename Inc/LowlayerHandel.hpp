/*
 * LowlayerHandel.hpp
 *
 *  Created on: 2019/05/01
 *      Author: —T‘¿
 */

#ifndef INC_LOWLAYERHANDEL_HPP_
#define INC_LOWLAYERHANDEL_HPP_

#include "CAN/CAN.hpp"
#include "stm32f303x8.h"
#include "MicroSW/MicroSW.hpp"
#include "main.h"
#include "ADC/ADC.hpp"

class LowlayerHandelTypedef
{
public:
	CanBus extcan;
	MicroSw sw1,sw2,sw3,sw4,sw5,sw6;
	ADC ad1,ad2,ad3,ad4,ad5,ad6;

	LowlayerHandelTypedef():
	sw1(GPIOA,GPIO_PIN_7),sw2(GPIOA,GPIO_PIN_9),sw3(GPIOA,GPIO_PIN_10),sw4(GPIOB,GPIO_PIN_0),sw5(GPIOB,GPIO_PIN_1),
	sw6(GPIOA,GPIO_PIN_8),ad1(2,3),ad2(2,2),ad3(2,1),ad4(1,4),ad5(1,2),ad6(1,1),
	extcan(CAN_ID_EXT,CAN_RTR_DATA)
	{

	}
};
//CAN_ID_EXT


#endif /* INC_LOWLAYERHANDEL_HPP_ */
