/*
 * Application.hpp
 *
 *  Created on: 2019/05/04
 *      Author: —T‘¿
 */

#ifndef APPLICATION_APPLICATION_HPP_
#define APPLICATION_APPLICATION_HPP_
#include "LowlayerHandel.hpp"
class App
{
	LowlayerHandelTypedef *plow;
	unsigned short node_id=0;
	unsigned char txbuf1[8]={0,};
	unsigned char txbuf2[8]={0,};
	unsigned char txbuf3[1]={0,};
	unsigned char txbuf4[6]={0,};
	void DivideData();
	float distance[6];
	bool TXok=false;
public:
	App(LowlayerHandelTypedef *_plow):plow(_plow)
	{
	}
	void TaskShift();
};




#endif /* APPLICATION_APPLICATION_HPP_ */
