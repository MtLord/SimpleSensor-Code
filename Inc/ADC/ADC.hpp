/*
 * ADC.hpp
 *
 *  Created on: 2019/05/14
 *      Author: —T‘¿
 */

#ifndef ADC_ADC_HPP_
#define ADC_ADC_HPP_


class ADC
{
	short channel=0;
	short adc_x=0;
public:
	ADC(short _adc_x,short _channel):channel(_channel),adc_x(_adc_x)
	{

	}
	static void Start();
	unsigned short GetValue();

};

#endif /* ADC_ADC_HPP_ */
