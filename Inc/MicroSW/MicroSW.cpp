

#include "MicroSW.hpp"

short MicroSw::GetPush()
{
	return HAL_GPIO_ReadPin(GPIOx,pin);
}
