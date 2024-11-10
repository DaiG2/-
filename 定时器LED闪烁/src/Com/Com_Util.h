#ifndef _UTIL_H_
#define _UTIL_H_

#include <INTRINS.H>
#define FOSC 11059200 // ����Ƶ��
#define NT   12       // ��Ƭ���Ĺ�������Ϊ12T

// 8bit�޷�����
typedef unsigned char u8;
// 16bit�޷�����
typedef unsigned int u16;
// 32bit�޷�����
typedef unsigned long u32;

/**
 * @brief ��ʱһ��ʱ��
 *
 * @param count ��ʱʱ������λ1ms
 */
void Delay1ms(u16 count);

#endif
