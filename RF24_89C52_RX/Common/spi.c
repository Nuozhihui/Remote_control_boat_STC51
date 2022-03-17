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
#include "spi.h"


/**
  * @brief :SPI��ʼ��(���)
  * @param :��
  * @note  :��
  * @retval:��
  */
void drv_spi_init( void )
{
	//�������� ����51��Ƭ������Ҫ
	//SCK MOSI NSS ����Ϊ�������
	SPI_SCK_PxM0 = IO_OUT_PUT_PP_M0 << SPI_SCK_PIN_BIT;
	SPI_SCK_PxM1 = IO_OUT_PUT_PP_M1 << SPI_SCK_PIN_BIT;
	
	SPI_MOSI_PxM0 = IO_OUT_PUT_PP_M0 << SPI_MOSI_PIN_BIT;
	SPI_MOSI_PxM1 = IO_OUT_PUT_PP_M1 << SPI_MOSI_PIN_BIT;
	
	SPI_NSS_PxM0 = IO_OUT_PUT_PP_M0 << SPI_NSS_PIN_BIT;
	SPI_NSS_PxM1 = IO_OUT_PUT_PP_M1 << SPI_NSS_PIN_BIT;
	
	//MISO ����Ϊ����
	SPI_MISO_PxM0 = IO_IN_PUT_ONLY_M0 << SPI_MISO_PIN_BIT;
	SPI_MISO_PxM1 = IO_IN_PUT_ONLY_M1 << SPI_MISO_PIN_BIT;
	
	//ʱ���õ�
	SPI_SCK = 0;	
	//MOSI MISO NSS�ø�
	SPI_MOSI = 1;		
	SPI_MISO = 1;
	SPI_NSS = 1;	
}

/**
  * @brief :SPI�շ�һ���ֽ�
  * @param :
  *			@TxByte: ���͵������ֽ�
  * @note  :�Ƕ���ʽ��һ���ȴ���ʱ���������Զ��˳�
  * @retval:���յ����ֽ�
  */
uint8_t drv_spi_read_write_byte( uint8_t TxByte )
{
	uint8_t i = 0, Data = 0;
	
	spi_set_clk_low( );
	
	for( i = 0; i < 8; i++ )			//һ���ֽ�8byte��Ҫѭ��8��
	{
		/** ���� */
		if( 0x80 == ( TxByte & 0x80 ))
		{
			spi_set_mosi_hight( );		//�������Ҫ���͵�λΪ 1 ���ø�IO����
		}
		else
		{
			spi_set_mosi_low( );		//�������Ҫ���͵�λΪ 0 ���õ�IO����
		}
		TxByte <<= 1;					//��������һλ���ȷ��͵������λ
		spi_set_clk_high( );			//ʱ�����ø�
		_nop_( );
	
		/** ���� */
		Data <<= 1;						//������������һλ���Ƚ��յ��������λ
		if( 1 == spi_get_miso( ))
		{
			Data |= 0x01;				//�������ʱIO����Ϊ������Ϊ���յ� 1
		}
		
		spi_set_clk_low( );				//ʱ�����õ�
		_nop_( );
	}
	
	return Data;		//���ؽ��յ����ֽ�
}

/**
  * @brief :SPI�շ��ַ���
  * @param :
  *			@ReadBuffer: �������ݻ�������ַ
  *			@WriteBuffer:�����ֽڻ�������ַ
  *			@Length:�ֽڳ���
  * @note  :�Ƕ���ʽ��һ���ȴ���ʱ���������Զ��˳�
  * @retval:��
  */
void drv_spi_read_write_string( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length )
{
	spi_set_nss_low( );			//Ƭѡ����
	
	while( Length-- )
	{
		*ReadBuffer = drv_spi_read_write_byte( *WriteBuffer );		//�շ�����
		ReadBuffer++;
		WriteBuffer++;			//��д��ַ��1
	}
	
	spi_set_nss_high( );		//Ƭѡ����
}