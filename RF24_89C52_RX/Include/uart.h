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
#ifndef __UART_H__
#define __UART_H__



#include "main.h"


#define SYSTEM_CLK_HZ				((uint32_t)11059200)	//系统时钟11.0592M


//串口接口定义
sbit	UART_TX						=P3^1;
sbit	UART_RX						=P3^0;

//IO在端口对应的Bit位置
#define UART_TX_PIN_BIT				1
#define UART_RX_PIN_BIT				0

//IO配置寄存器
#define UART_TX_PxM0				P3M0
#define UART_TX_PxM1				P3M1

#define UART_RX_PxM0				P3M0
#define UART_RX_PxM1				P3M1

//串口工作模式
#define UART_MODE					((uint8_t)0xC0)
#define UART_SHITT_REGSISTER		((uint8_t)0x00)		//移位寄存器
#define UART_8BAUDRATE_VOLATILE		((uint8_t)0x40)		//8位波特率可变	
#define UART_9BAUDRATE				((uint8_t)0x80)		//9位波特率	
#define UART_9BAUDRATE_VOLATILE		((uint8_t)0xC0)		//9位波特率可变	
#define UART_RX						((uint8_t)0x10)		//接收功能

//定时器1控制定义
#define TIM1_MODE					((uint8_t)0x30)
#define TIM1_MODE_0					((uint8_t)0x00)		//TIM1模式0	13位计数器/定时器
#define TIM1_MODE_1					((uint8_t)0x10)		//TIM1模式1	16位计数器/定时器
#define TIM1_MODE_2					((uint8_t)0x20)		//TIM1模式2 8位自动重装
#define TIM1_MODE_3					((uint8_t)0x30)		//TIM1模式3 2个8位定时器







void drv_uart_init( );
void drv_uart_tx_bytes( uint8_t* TxBuffer, uint8_t Length );
uint8_t drv_uart_rx_bytes( uint8_t* RxBuffer );



#endif