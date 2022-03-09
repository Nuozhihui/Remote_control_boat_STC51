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
						
		    OLED(IIC):  VCC    3.3V
				        GND        GND
						SCL        P1^6
						SDA        P1^7
						
    ����޸�ʱ�䣻2018��8��1�� 12:00:00

*/
#include "main.h"

const char *content = "yunguokeji";
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};
void main()
{
	u32 num=0;
	OLED_Init();			   //��ʼ��OLED  
    OLED_Clear();
	
	drv_spi_init( );           //SPI��ʼ��
	
	
	NRF24L01_Gpio_Init( );    //RF24L01���ų�ʼ��
	

	NRF24L01_check( );	 	  //���nRF24L01
	RF24L01_Init( );
	RF24L01_Set_Mode( MODE_TX );		//����ģʽ
	OLED_ShowCHinese(0,3,0);     //��
	OLED_ShowCHinese(18,3,1);    //��
	OLED_ShowCHinese(36,3,2);    //��
	OLED_ShowCHinese(54,3,3);    //��
	OLED_ShowCHinese(72,3,4);    //��
	
	OLED_ShowCHinese(0,0,5);     //��
	OLED_ShowCHinese(16,0,6);    //��
	OLED_ShowCHinese(32,0,7);    //��
	OLED_ShowCHinese(48,0,8);    //��
	OLED_ShowCHinese(64,0,9);    //��
	OLED_ShowCHinese(80,0,10);   //��
	OLED_ShowCHinese(96,0,11);   //��
	OLED_ShowCHinese(112,0,12);  //˾
	//****************����********************************************//
	while(1)
	{
		 RF24L01_Set_Mode( MODE_TX );		//����ģʽ
		 NRF24L01_TxPacket( content, 10 );		//ģʽ1���͹̶��ַ�,1Sһ��
//		 NRF24L01_TxPacket( UART_BUFFER, 10 );		//ģʽ1���͹̶��ַ�,1Sһ��
		 num++;
		 OLED_ShowNum(90,3,num,3,16);
		 delay_ms( 1000 );
	}
}