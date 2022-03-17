
#include "main.h"

const char *content = "yunguokeji";
u8   UART_BUFFER[64]={0},RF24L01RxBuffer[64]={0};

unsigned char pwm_motor_val =255;//���ҵ��ռ�ձ�ֵ ȡֵ��Χ0-170��0���
unsigned char pwm_t;//����

sbit BEEP=P2^3;
sbit PWMA = P0^0;//
sbit PWMB = P0^5;//

sbit AIN1 = P0^1;//
sbit AIN2 = P0^2;//
sbit BIN1 = P0^3;
sbit BIN2 = P0^4;//

int MOD=2;		//1:ǰ��  2:ֹͣ  3:��ת  4:��ת
void F_Date()
{
	if(MOD==1)		//ǰ
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

//��ʱ��0�ж�
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
	OLED_Init();			   //��ʼ��OLED  
    OLED_Clear();
	
	drv_spi_init( );           //SPI��ʼ��
	
	
	NRF24L01_Gpio_Init( );    //RF24L01���ų�ʼ��
	

	NRF24L01_check( );	 	  //���nRF24L01
	RF24L01_Init( );
	RF24L01_Set_Mode( MODE_RX );		//����ģʽ
	OLED_ShowCHinese(0,2,0);     //��

	
	
	
	TMOD |= 0x02;//8λ�Զ���װģ��
	TH0 = 220;
	TL0 = 220;//11.0592M������ռ�ձ�����ֵ��256,���100HZ
	TR0 = 1;//������ʱ��0
	ET0 = 1;//����ʱ��0�ж�
	EA	= 1;//���ж�����
	
	AIN2 = 1;
	BIN2 = 1;
	
	PWMA=0;
	PWMB=0;

	//********************************����*************************************//
	while(1)
	{
//		
		 j = NRF24L01_RxPacket( RF24L01RxBuffer );		//�����ֽ�
	
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