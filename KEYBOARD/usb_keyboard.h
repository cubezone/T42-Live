
#ifndef _USB_KEYBOARD_H
#define _USB_KEYBOARD_H

#include "stm32f10x_map.h"
typedef unsigned char  uint8_t;

void USB_Send_Key_Press(char c, uint8_t modifier);

void USB_Send_Key_Release(char c, uint8_t modifier);

void USB_Send_All_Keys_Released(uint8_t modifier);

#endif
