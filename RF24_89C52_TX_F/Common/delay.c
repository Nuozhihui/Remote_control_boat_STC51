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
#include "delay.h"

/**
  * @brief :1MS延时函数
  * @param :
  * @note  :12MHz 下1MS延时
  * @retval:无
  */
void delay_1ms( )
{
	uint16_t Ms = 1;
	uint32_t j = 80;
	
	while( Ms-- )
	{
		while( j-- );
	}
}

/**
  * @brief :MS延时函数
  * @param :
  *	@Ms:延时的MS数
  * @note  :无
  * @retval:无
  */
void delay_ms( uint16_t Ms )
{
	while( Ms-- )
	{
		delay_1ms( );
	}
}