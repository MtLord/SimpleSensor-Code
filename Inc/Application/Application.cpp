/*
 * Application.cpp
 *
 *  Created on: 2019/05/04
 *      Author: 裕汰
 */

#include "Application.hpp"
#include "DefineOrder.h"
#include "stdio.h"
#include "math.h"
#include "DefineLED.h"
extern unsigned char RxFIFO_Data[6];
extern CAN_RxHeaderTypeDef RXmsg;
extern bool CanRxFlag;
extern bool IntFlag;
int tx_led=0;
void App::DivideData()
{
	unsigned short tempdata[6]={0,};
	tempdata[0]=plow->ad1.GetValue();
	tempdata[1]=plow->ad2.GetValue();
	tempdata[2]=plow->ad3.GetValue();
	tempdata[3]=plow->ad4.GetValue();
	tempdata[4]=plow->ad5.GetValue();
	tempdata[5]=plow->ad6.GetValue();


	//distance[0]=19501.14 * pow(tempdata[0] ,-1.256676);
		this->txbuf3[0]	=plow->sw1.GetPush();
		this->txbuf3[0]	=plow->sw2.GetPush()<<1;
		this->txbuf3[0]	=plow->sw3.GetPush()<<2;
		this->txbuf3[0]	=plow->sw4.GetPush()<<3;
		this->txbuf3[0]	=plow->sw5.GetPush()<<4;
		this->txbuf3[0]	=plow->sw6.GetPush()<<5;
		//txbuf3[0]=~txbuf3[0]; //押しているときを1に変更

	this->txbuf1[0]=((unsigned char *)&tempdata[0])[0];
	this->txbuf1[1]=((unsigned char *)&tempdata[0])[1];
	this->txbuf1[2]=((unsigned char *)&tempdata[1])[0];
	this->txbuf1[3]=((unsigned char *)&tempdata[1])[1];
	this->txbuf1[4]=((unsigned char *)&tempdata[2])[0];
	this->txbuf1[5]=((unsigned char *)&tempdata[2])[1];
	this->txbuf1[6]=((unsigned char *)&tempdata[3])[0];
	this->txbuf1[7]=((unsigned char *)&tempdata[3])[1];

	this->txbuf2[0]=((unsigned char *)&tempdata[4])[0];
	this->txbuf2[1]=((unsigned char *)&tempdata[4])[1];
	this->txbuf2[2]=((unsigned char *)&tempdata[5])[0];
	this->txbuf2[3]=((unsigned char *)&tempdata[5])[1];


}

void App::TaskShift()
{
	if(IntFlag)
	{
		this->DivideData();
	}
	if(CanRxFlag)
	{
		if(RXmsg.ExtId>>ORDER_BIT_Pos==Get_SENSOR)
		{
			plow->extcan.Send(Get_SENSOR<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos,8,txbuf1); //送信要求が来たら12バイト分送信
			if(plow->extcan.Send(Get_SENSOR<<ORDER_BIT_Pos|0x2<<NODE_ID_Pos,4,txbuf2)!=0)
			{

			}
			else
			{
				if(tx_led>7){
					TOGGLE_TX_LED;
					tx_led=0;
				}
				else{
					tx_led++;
				}

			}
		}
		if(RXmsg.ExtId>>ORDER_BIT_Pos==GET_MICROSWITCH)
		{
			if(plow->extcan.Send(GET_MICROSWITCH<<ORDER_BIT_Pos,1,txbuf3)!=0){

			}
			else
			{
				if(tx_led>7)
				{
					TOGGLE_TX_LED;
					tx_led=0;
				}
				else{
				tx_led++;
				}
			}
		}
		CanRxFlag=false;
	}
}



