#include "main.h"


sbit KEY1=P2^0;
sbit KEY2=P2^1;
sbit KEY3=P2^3;
sbit KEY4=P2^2;

const char *content = "yunguokeji";
	unsigned char TxBuf[20]={0};	 // 
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};
void main()
{
	u32 num=0;
	OLED_Init();			   //初始化OLED  
    OLED_Clear();
	
	drv_spi_init( );           //SPI初始化
	
	
	NRF24L01_Gpio_Init( );    //RF24L01引脚初始化
	

	NRF24L01_check( );	 	  //检测nRF24L01
	RF24L01_Init( );
	RF24L01_Set_Mode( MODE_TX );		//发送模式

	
	//****************发送********************************************//
	while(1)
	{
		 RF24L01_Set_Mode( MODE_TX );		//发送模式
		 
//		 NRF24L01_TxPacket( UART_BUFFER, 10 );		//模式1发送固定字符,1S一包
//		 num++;
//		 OLED_ShowNum(90,3,num,3,16);
//		 delay_ms( 1000 );
		
		if( KEY1==0)
		{
			 delay_ms( 5);
			 if( KEY1==0)
				{
					 TxBuf[1] = 1 ;
					 NRF24L01_TxPacket(TxBuf, 2 );		//模式1发送固定字符,1S一包
					OLED_Clear();  
					OLED_ShowString(10,10,"advance",4);
				}
		}else if( KEY2==0)
		{
			 delay_ms( 5);
			 if( KEY2==0)
				{
					 TxBuf[1] = 2 ;
					 NRF24L01_TxPacket(TxBuf, 2 );		//模式1发送固定字符,1S一包
					OLED_Clear();  
					OLED_ShowString(10,10,"Stop",4);
					
				}
		}else if( KEY3==0)
		{
			 delay_ms( 5);
			 if( KEY3==0)
				{
					 TxBuf[1] = 3 ;
					 NRF24L01_TxPacket(TxBuf, 2 );		//模式1发送固定字符,1S一包
					OLED_Clear();  
					OLED_ShowString(10,10,"left",4);
				}
		}else if( KEY4==0)
		{
			 delay_ms( 5);
			 if( KEY4==0)
				{
					 TxBuf[1] = 4 ;
					 NRF24L01_TxPacket(TxBuf, 2 );		//模式1发送固定字符,1S一包
					OLED_Clear();  
					OLED_ShowString(10,10,"right",4);
				}
		}else{
			 TxBuf[1] = 0 ;
					 NRF24L01_TxPacket(TxBuf, 2 );		//模式1发送固定字符,1S一包
		}
		TxBuf[1] = 0x00;
		TxBuf[2] = 0x00;
	}
}