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
#include "uart.h"

/**
  * @brief :���ڳ�ʼ��
  * @param :��
  * @note  :��
  * @retval:��
  */
void drv_uart_init( )
{
	//�������� ����51��Ƭ������Ҫ
	//TX����Ϊ��� RX����Ϊ����
	UART_TX_PxM0 |= IO_OUT_PUT_PP_M0 << UART_TX_PIN_BIT;
	UART_TX_PxM1 |= IO_OUT_PUT_PP_M1 << UART_TX_PIN_BIT;
	UART_RX_PxM0 |= IO_IN_PUT_ONLY_M0 << UART_RX_PIN_BIT;
	UART_RX_PxM1 |= IO_IN_PUT_ONLY_M1 << UART_RX_PIN_BIT;
	UART_TX = 1;
	
	//��������
	SCON &= (uint8_t)((uint8_t)( ~( UART_MODE | UART_RX )));	//��SM0 SM1 REN
	SCON |= (uint8_t)( UART_8BAUDRATE_VOLATILE | UART_RX );
	
	//TIM1����
	TMOD &= (uint8_t)((uint8_t)( ~TIM1_MODE ));
	TMOD |= TIM1_MODE_2;	//8λ�Զ���װ
	PCON = 0x00;
	TH1 = 0xFD;				//������Ĭ������Ϊ9600
	TL1 = 0xFD;
	
	TI = 1;					//�巢�ͱ�־						
	TR1 = 1;				//ʹ�ܶ�ʱ��
}

/**
  * @brief :���ڷ�������
  * @param :
  *			@TxBuffer:���������׵�ַ
  *			@Length:���ݳ���
  * @note  :��
  * @retval:��
  */
void drv_uart_tx_bytes( uint8_t* TxBuffer, uint8_t Length )
{
	while( Length-- )
	{
		while( 0 == TI );		//�ȴ��ϴη������
		TI = 0;					//���־λ
		SBUF = *TxBuffer;		//��������
		TxBuffer++;
	}
}

/**
  * @brief :���ڽ�������
  * @param :
  *			@RxBuffer:���������׵�ַ
  * @note  :��
  * @retval:���յ����ֽڸ���
  */
uint8_t drv_uart_rx_bytes( uint8_t* RxBuffer )
{
	uint8_t l_RxLength = 0;
	uint16_t l_UartRxTimOut = 0x7FFF;
	
	while( l_UartRxTimOut-- )		//�ڳ�ʱ��Χ�ڼ������
	{
		if( 0 != RI )				//����Ƿ���յ�����
		{
			RI = 0;					//���־λ		
			*RxBuffer = SBUF;		//������
			RxBuffer++;
			l_RxLength++;
			l_UartRxTimOut = 0x7FFF;//���ó�ʱ���
		}
	}
	
	return l_RxLength;			//�ȴ���ʱ�����ݽ������
}

