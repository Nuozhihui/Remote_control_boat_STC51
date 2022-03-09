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
#include "main.h"

const char *content = "yunguokeji";
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};
void main()
{
	u8 j;
	u32 num=0;
	OLED_Init();			   //��ʼ��OLED  
    OLED_Clear();
	
	drv_spi_init( );           //SPI��ʼ��
	
	
	NRF24L01_Gpio_Init( );    //RF24L01���ų�ʼ��
	

	NRF24L01_check( );	 	  //���nRF24L01
	RF24L01_Init( );
	RF24L01_Set_Mode( MODE_RX );		//����ģʽ
	OLED_ShowCHinese(0,2,0);     //��
	OLED_ShowCHinese(18,2,1);    //��
	OLED_ShowCHinese(36,2,2);    //��
	OLED_ShowCHinese(54,2,3);    //��
	OLED_ShowCHinese(72,2,4);    //��
	
	OLED_ShowCHinese(0,0,5);     //��
	OLED_ShowCHinese(16,0,6);    //��
	OLED_ShowCHinese(32,0,7);    //��
	OLED_ShowCHinese(48,0,8);    //��
	OLED_ShowCHinese(64,0,9);    //��
	OLED_ShowCHinese(80,0,10);   //��
	OLED_ShowCHinese(96,0,11);   //��
	OLED_ShowCHinese(112,0,12);  //˾
	delay_ms(1000);
	//********************************����*************************************//
	while(1)
	{
		 RF24L01_Set_Mode( MODE_RX );		//����ģʽ
		 j = NRF24L01_RxPacket( RF24L01RxBuffer );		//�����ֽ�
		if( 0 != j )
		{
			OLED_Clear();
			OLED_ShowString(0,num,RF24L01RxBuffer,8);		
			num++;
	        if(num==8)  num=0;
		}
	}
}