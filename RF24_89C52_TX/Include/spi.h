/*

    GT-24 V1.0 (RF24L01) ���Կ�������

    ���ߣ����ƿƼ����޹�˾
	�Ա�����:https://shop532831232.taobao.com
	
	����оƬ��89C52
	
	��·���ӣ�  RF24L01�� VCC        3.3V
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
						
    ����޸�ʱ�䣻2018��8��1�� 12:00:00

*/
#ifndef __SPI_H__
#define __SPI_H__


#include <reg52.h>
#include <intrins.h>
#include "typedef.h"


//SPI�ӿڶ���
sbit	SPI_SCK						=P1^1;
sbit	SPI_MOSI					=P1^4;
sbit	SPI_MISO					=P1^2;
sbit	SPI_NSS						=P1^3;

//IO�ڶ˿ڶ�Ӧ��Bitλ��
#define SPI_SCK_PIN_BIT				7
#define SPI_MOSI_PIN_BIT			5
#define SPI_MISO_PIN_BIT			6
#define SPI_NSS_PIN_BIT				3

//IO���üĴ���
#define SPI_SCK_PxM0				P1M0
#define SPI_SCK_PxM1				P1M1

#define SPI_MOSI_PxM0				P1M0
#define SPI_MOSI_PxM1				P1M1

#define SPI_MISO_PxM0				P1M0
#define SPI_MISO_PxM1				P1M1

#define SPI_NSS_PxM0				P1M0
#define SPI_NSS_PxM1				P1M1



//������������
#define spi_set_clk_high( )			SPI_SCK = 1		//ʱ���ø�
#define spi_set_clk_low( )			SPI_SCK = 0		//ʱ���õ�

#define spi_set_mosi_hight( )		SPI_MOSI = 1	//���ͽ��ø�
#define spi_set_mosi_low( )			SPI_MOSI = 0	//���ͽ��õ�

#define spi_get_miso( )				(( 1 != SPI_MISO ) ? 0 : 1 )

#define spi_set_nss_high( )			SPI_NSS = 1		//Ƭѡ�ø�
#define spi_set_nss_low( )			SPI_NSS = 0		//Ƭѡ�õ�


void drv_spi_init( void );
uint8_t drv_spi_read_write_byte( uint8_t TxByte );
void drv_spi_read_write_string( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length );

#endif

