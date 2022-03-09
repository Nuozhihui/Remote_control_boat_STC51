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
#include "main.h"

const char *content = "yunguokeji";
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};
void main()
{
	u8 j;
	u32 num=0;
	OLED_Init();			   //初始化OLED  
    OLED_Clear();
	
	drv_spi_init( );           //SPI初始化
	
	
	NRF24L01_Gpio_Init( );    //RF24L01引脚初始化
	

	NRF24L01_check( );	 	  //检测nRF24L01
	RF24L01_Init( );
	RF24L01_Set_Mode( MODE_RX );		//接收模式
	OLED_ShowCHinese(0,2,0);     //接
	OLED_ShowCHinese(18,2,1);    //收
	OLED_ShowCHinese(36,2,2);    //数
	OLED_ShowCHinese(54,2,3);    //据
	OLED_ShowCHinese(72,2,4);    //：
	
	OLED_ShowCHinese(0,0,5);     //果
	OLED_ShowCHinese(16,0,6);    //云
	OLED_ShowCHinese(32,0,7);    //科
	OLED_ShowCHinese(48,0,8);    //技
	OLED_ShowCHinese(64,0,9);    //有
	OLED_ShowCHinese(80,0,10);   //限
	OLED_ShowCHinese(96,0,11);   //公
	OLED_ShowCHinese(112,0,12);  //司
	delay_ms(1000);
	//********************************接收*************************************//
	while(1)
	{
		 RF24L01_Set_Mode( MODE_RX );		//接收模式
		 j = NRF24L01_RxPacket( RF24L01RxBuffer );		//接收字节
		if( 0 != j )
		{
			OLED_Clear();
			OLED_ShowString(0,num,RF24L01RxBuffer,8);		
			num++;
	        if(num==8)  num=0;
		}
	}
}