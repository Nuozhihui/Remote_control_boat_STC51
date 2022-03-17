/*

    GT-24 V1.0 (RF24L01) 测试开发程序

    编者：果云科技有限公司
	淘宝店铺:https://shop532831232.taobao.com
	
	适用芯片：89C52
	
	线路连接：  RF24L01： VCC        3.3V
					     GND        GND
						  CE        P1^0
						 IRQ        P1^5
                         CSN        P1^3
					     SCK        P1^1
						MOSI        P1^4
						MISO        P1^2
						
		    OLED(IIC):  VCC        3.3V
				        GND        GND
						SCL        P1^6
						SDA        P1^7
						
    最后修改时间；2018年8月1日 12:00:00

*/
#ifndef __DELAY_H__
#define __DELAY_H__

#include "typedef.h"


void delay_1ms( );
void delay_ms( uint16_t Ms );

#endif