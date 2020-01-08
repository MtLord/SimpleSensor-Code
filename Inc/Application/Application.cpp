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
	unsigned short tempdata[9]={0,};
	tempdata[0]=plow->ad1.GetValue();
	tempdata[1]=plow->ad2.GetValue();
	tempdata[2]=plow->ad3.GetValue();
	tempdata[3]=plow->ad4.GetValue();
	tempdata[4]=plow->ad5.GetValue();
	tempdata[5]=plow->ad6.GetValue();
#ifdef USE_I2C_DEVICE
	tempdata[6]=plow->vl53l0x_0.readRangeContinuousMillimeters();
	tempdata[7]=plow->vl53l0x_1.readRangeContinuousMillimeters();
	tempdata[8]=plow->vl53l0x_2.readRangeContinuousMillimeters();
#endif
	//distance[0]=19501.14 * pow(tempdata[0] ,-1.256676);
		this->txbuf3[0]	=plow->sw6.GetPush();
		this->txbuf3[0]	=(txbuf3[0]<<1)+plow->sw5.GetPush();
		this->txbuf3[0]	=(txbuf3[0]<<1)+plow->sw4.GetPush();
		this->txbuf3[0]	=(txbuf3[0]<<1)+plow->sw3.GetPush();
		this->txbuf3[0]	=(txbuf3[0]<<1)+plow->sw2.GetPush();
		this->txbuf3[0]	=(txbuf3[0]<<1)+plow->sw1.GetPush();
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

	this->txbuf4[0]=((unsigned char *)&tempdata[6])[0];
	this->txbuf4[1]=((unsigned char *)&tempdata[6])[1];
	this->txbuf4[2]=((unsigned char *)&tempdata[7])[0];
	this->txbuf4[3]=((unsigned char *)&tempdata[7])[1];
	this->txbuf4[4]=((unsigned char *)&tempdata[8])[0];
	this->txbuf4[5]=((unsigned char *)&tempdata[8])[1];

}

void App::TaskShift()
{
	if(IntFlag)
	{
		this->DivideData();
	}
	if(CanRxFlag)
	{
		if(RXmsg.ExtId>>ORDER_BIT_Pos==Get_SENSOR)//送信要求が来たら12バイト分送信
		{
		  while(TXok==false)
		  {
			 if(plow->extcan.Send(Get_SENSOR<<ORDER_BIT_Pos|0x1<<NODE_ID_Pos,8,txbuf1)!=0)
			 {

			 }
			 else
			 {
				 TXok=true;
			 }
		  }
		  TXok=false;

		  while(TXok==false)
		  {
			if(plow->extcan.Send(Get_SENSOR<<ORDER_BIT_Pos|0x2<<NODE_ID_Pos,4,txbuf2)!=0)
			{

			}
			else
			{
				if(tx_led>7)
				{
					TOGGLE_TX_LED;
					tx_led=0;
				}
				else
				{
					tx_led++;
				}
				TXok=true;
			}
		  }
		  TXok=false;
		}

		if(RXmsg.ExtId>>ORDER_BIT_Pos==GET_MICROSWITCH)
		{
		  while(TXok==false)
		  {
			if(plow->extcan.Send(GET_MICROSWITCH<<ORDER_BIT_Pos|1,1,txbuf3)!=0)
			{

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
				TXok=true;
			}
		  }
		  TXok=false;
		}

		if(RXmsg.ExtId>>ORDER_BIT_Pos==GET_I2C_SENSER)
		{
			while(TXok==false)
			{
				if(plow->extcan.Send(GET_I2C_SENSER<<ORDER_BIT_Pos|1,3,txbuf4)!=0)
				{

				}
				else
				{
					if(tx_led>9)
					{
						TOGGLE_TX_LED;
						tx_led=0;
					}
					else
					{
						tx_led++;
					}
						TXok=true;
				}
			}
		}

		CanRxFlag=false;
	}
}



