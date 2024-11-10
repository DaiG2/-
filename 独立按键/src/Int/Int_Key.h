#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include <STC89C5xRC.H>
#include "Util.h"

/**
 * @brief ���SW1�����Ƿ���
 *
 * @return bit �ǻ��
 */
bit Int_Key_IsSW1Pressed();

/**
 * @brief ���SW2�����Ƿ���
 *
 * @return bit �ǻ��
 */
bit Int_Key_IsSW2Pressed();

/**
 * @brief ���SW3�����Ƿ���
 *
 * @return bit �ǻ��
 */
bit Int_Key_IsSW3Pressed();

/**
 * @brief ���SW4�����Ƿ���
 *
 * @return bit �ǻ��
 */
bit Int_Key_IsSW4Pressed();

#endif /* __INT_KEY_H__ */
