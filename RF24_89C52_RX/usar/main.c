
#include "main.h"

const char *content = "yunguokeji";
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};

unsigned char pwm_motor_val =255;//左右电机占空比值 取值范围0-170，0最快
unsigned char pwm_t;//周期

sbit BEEP=P2^3;
sbit PWMA = P0^0;//
sbit PWMB = P0^5;//

sbit AIN1 = P0^1;//
sbit AIN2 = P0^2;//
sbit BIN1 = P0^3;
sbit BIN2 = P0^4;//

int MOD=2;		//1:前进  2:停止  3:左转  4:右转
void F_Date()
{
	if(MOD==1)		//前
	{
		AIN1 = 0;
		BIN1 = 0;
	}else if(MOD==2){
		
		AIN1 = 1;
		BIN1 = 1;
	}else if(MOD==3){
		
		AIN1 = 1;
		BIN1 = 0;
	}else if(MOD==4){
		
		AIN1 = 0;
		BIN1 = 1;
	}
	
}

//定时器0中断
void timer0() interrupt 1
{
	pwm_t++;
	if(pwm_t == 255)
	{
		 F_Date();
	}
	if(pwm_motor_val == pwm_t)
	{	
		AIN1 = 1;			
		BIN1 = 1;	
	}
}

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

	
	
	
	TMOD |= 0x02;//8位自动重装模块
	TH0 = 220;
	TL0 = 220;//11.0592M晶振下占空比最大比值是256,输出100HZ
	TR0 = 1;//启动定时器0
	ET0 = 1;//允许定时器0中断
	EA	= 1;//总中断允许
	
	AIN2 = 1;
	BIN2 = 1;
	
	PWMA=0;
	PWMB=0;

	//********************************接收*************************************//
	while(1)
	{
//		
		 j = NRF24L01_RxPacket( RF24L01RxBuffer );		//接收字节
	
		if( 0 != j )
		{
//			OLED_Clear();
//			OLED_ShowString(0,num,RF24L01RxBuffer,8);		
//			num++;
//	    if(num==8)  num=0;
		if( RF24L01RxBuffer[1]==0)
			{
				MOD=2;
				BEEP=0;
				
				pwm_motor_val=255;
			}else if( RF24L01RxBuffer[1]==1)
			{
				MOD=1;
				BEEP=0;
				
				pwm_motor_val=200;
			}else if( RF24L01RxBuffer[1]==2)
			{
				MOD=2;
				BEEP=1;
					pwm_motor_val=255;
			}else if( RF24L01RxBuffer[1]==3)
			{
				MOD=3;
				BEEP=0;
				pwm_motor_val=200;
			}else if( RF24L01RxBuffer[1]==4)
			{
				MOD=4;
				BEEP=1;
				pwm_motor_val=200;
			}else{
				
				pwm_motor_val=255;
			}
	}else{
				
				pwm_motor_val=255;
			}
//	
	
	}
}