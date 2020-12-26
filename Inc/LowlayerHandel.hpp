/*
 * LowlayerHandel.hpp
 *
 *  Created on: 2019/05/01
 *      Author: �T��
 */

#ifndef INC_LOWLAYERHANDEL_HPP_
#define INC_LOWLAYERHANDEL_HPP_

#include "CAN/CAN.hpp"
#include "stm32f303x8.h"
#include "MicroSW/MicroSW.hpp"
#include "main.h"
#include "ADC/ADC.hpp"
#include <stdio.h>

//#define USE_I2C_DEVICE
class LowlayerHandelTypedef
{
public:
	CanBus extcan;
	MicroSw sw1,sw2,sw3,sw4,sw5,sw6,sw7;
	ADC ad1,ad2,ad3,ad4,ad5,ad6;

	LowlayerHandelTypedef():
	sw1(GPIOB,GPIO_PIN_0),sw2(GPIOB,GPIO_PIN_1),sw3(GPIOA,GPIO_PIN_8),sw4(GPIOA,GPIO_PIN_9),sw5(GPIOA,GPIO_PIN_10),
	sw6(GPIOA,GPIO_PIN_7),sw7(GPIOB,GPIO_PIN_4),
	ad1(2,3),ad2(2,2),ad3(2,1),ad4(1,4),ad5(1,2),ad6(1,1),
	extcan(CAN_ID_EXT,CAN_RTR_DATA)
	{

	}
	void DebugADC()
	{
		printf("%d %d %d %d %d %d\n\r",ad1.GetValue(),ad2.GetValue(),ad3.GetValue(),ad4.GetValue(),ad5.GetValue(),ad6.GetValue());
	}
	void DebugSW()
	{
		printf("%d %d %d %d %d %d\n\r",sw1.GetPush(),sw2.GetPush(),sw3.GetPush(),sw4.GetPush(),sw5.GetPush(),sw6.GetPush());
	}
};



#endif /* INC_LOWLAYERHANDEL_HPP_ */
