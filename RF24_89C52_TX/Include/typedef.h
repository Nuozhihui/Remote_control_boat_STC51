#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

typedef   signed           char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
//typedef   signed       		 int64_t;

    /* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
//typedef unsigned            uint64_t;

typedef unsigned          char u8;
typedef unsigned short     int u16;
typedef unsigned           int u32;
//typedef unsigned            uint64_t;


//===================ADD========================ADD===========================//


//��Ӳ��ֱ�׼ͷ�ļ�û�еļĴ�������
//IO�����������üĴ��� --> PxMx,����51��Ƭ��û���⼸���Ĵ���
sfr P0M0			= 0x93;
sfr P0M1			= 0x94;
sfr P1M0			= 0x91;
sfr P1M1			= 0x92;
sfr P2M0			= 0x95;
sfr P2M1			= 0x96;
sfr P3M0			= 0xB1;
sfr P3M1			= 0xB2;

/** IO���Զ��� */
//׼˫���
#define IO_IN_OUT_PUT_M0			((uint8_t)0x00)
#define IO_IN_OUT_PUT_M1			((uint8_t)0x00)
//�������
#define IO_OUT_PUT_PP_M0			((uint8_t)0x00)
#define IO_OUT_PUT_PP_M1			((uint8_t)0x01)
//��Ϊ����(����)
#define IO_IN_PUT_ONLY_M0			((uint8_t)0x01)
#define IO_IN_PUT_ONLY_M1			((uint8_t)0x00)
//��©
#define IO_OPEN_DRAIN_M0			((uint8_t)0x01)
#define IO_OPEN_DRAIN_M1			((uint8_t)0x01)


//===================ADD========================ADD===========================//

#endif
