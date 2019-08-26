/*
 * ADC.cpp
 *
 *  Created on: 2019/05/14
 *      Author: —T‘¿
 */

#include "ADC.hpp"
#include "stm32f3xx_hal.h"
#include"adc.h"

uint16_t adcValue1[6]={0,};
uint16_t adcValue2[6]={0,};



void ADC::Start()
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcValue1, 3);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *)adcValue2, 3);
}

unsigned short ADC::GetValue()
{
	if(adc_x==1)
	{
		switch(channel)
		{
		case 1:
			return adcValue1[0];
			break;
		case 2:
			return adcValue1[1];
			break;
		case 4:
			return adcValue1[2];
			break;
		}
	}
	else if(adc_x==2)
	{
		return adcValue2[this->channel-1];
	}
	return 0;
}
