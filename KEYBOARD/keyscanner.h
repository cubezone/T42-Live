#ifndef __KEY_SCANNER_H
#define __KEY_SCANNER_H

//#include "stm32f1xx_hal.h"
#include <stm32f10x_map.h>
#include <stm32f10x_nvic.h>      
#include <stm32f10x_type.h>  

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;


void KS_Init(void);
void KS_PrintScanLines(void);
uint8_t KS_ReadScanCode(uint8_t* scanCodeBuffer, uint8_t bufferLength, uint8_t* modifiers);

#endif
