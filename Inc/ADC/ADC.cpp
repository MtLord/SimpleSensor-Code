/*
 * ADC.cpp
 *
 *  Created on: 2019/05/14
 *      Author: —T‘¿
 */

#include "ADC.hpp"


uint16_t adcValue1[6];
uint16_t adcValue2[6];



void ADC::Start()
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcValue1, 3);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *)adcValue2, 3);
}

unsigned short ADC::GetValue()
{
	if(adc_x==1)
	{
		return adcValue1[this->channel-1];
	}
	else if(adc_x==2)
	{
		return adcValue2[this->channel-1];
	}
}
