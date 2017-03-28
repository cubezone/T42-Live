//#include <stm32f10x_lib.h>
#include <stm32f10x_map.h>
#include <stm32f10x_nvic.h>      

#include "sys.h"
#include "delay.h"	   
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"  
#include "keyscanner.h"
#include "usb_keyboard.h"
#include "stdio.h"
#include "mouse.h"

extern u8 EP1BUSY;			//键盘数据发送忙标志 
extern u8 EP2BUSY;			//鼠标数据发送忙标志
extern u8 INIT_OK;

u8 keysScanned;
#define scanCodeBufferSize  8
u8 scanCodeBuffer[scanCodeBufferSize];
u8 modifiers;
u8 keypress;
u8 mousepress;
u8 i;
u8 ret;

/*

PA0..PA7 SenceLine
PB4 DriverLine CLK
PB5 DriverLine DATA

PA15 Mouse ClK
PB3  Mouse DATA
PB1  Mouse RESET

PB0  Keyboard Power Button
PC13 Keyboard Fn Button

*/

int main(void)
{
	Stm32_Clock_Init(9);//系统时钟设置
	delay_init(72);		//延时初始化
	
	//USB配置
	USB_Interrupts_Config();    
	
	RCC->APB2ENR |= 0x00000001; //afio
  AFIO->MAPR   = (0x00FFFFFF & AFIO->MAPR)|0x02000000;  //disable JTAG  release PB3,PB4 to GPIO
	RCC->APB2ENR |= 0X0000001c;//IO PORT A,B,C
	
	GPIOB->CRH = 0X33333333;    //输出 
	GPIOB->CRL = 0X33333333;    //输出
	
	Set_USBClock();  

	USB_Init();
	
	KS_Init();  //PA0..PA7; 595 PB4 PB5 init
	
	ret = Init_Mouse(); //ps/2 PB3 PA15 exti15 init	, PB1 reset
	
	keypress = 0;
	mousepress = 0;

	while(1)
	{
		  
// mouse loop		
/*
			if(PS2_Status&0x80)
			{		  
				//get mouse data	
				Mouse_Data_Pro(); 					
				Mouse_Send(MouseX.bt_mask,MouseX.x_pos,MouseX.y_pos);			
				PS2_Status=MOUSE;				
				PS2_En_Data_Report();	
			}else if(PS2_Status&0x40)
			{
				Mouse_Send(0,0,0);
				PS2_Status=MOUSE;	
			}		
*/			
// keyboard loop		

		  modifiers = 0;
		  scanCodeBuffer[0] = 0;
		  keysScanned = KS_ReadScanCode(scanCodeBuffer, scanCodeBufferSize, &modifiers);
			if(keysScanned > 0 ||  modifiers != 0)
			{
				if (keysScanned > 0)
				{						 
					USB_Send_Key_Press(scanCodeBuffer[0], modifiers);
				}else{
					USB_Send_Key_Press(0x00, modifiers);
				}			
				keypress = 1;
			}
			else if (keypress == 1 )
			{
					USB_Send_All_Keys_Released(0x00);
					keypress =0;
			}			
			delay_ms(10);			
	}
}	

//test
/*
	while(1)
	{
		if(EP2BUSY==0)
		{
			EP2BUSY = 1;	
			Mouse_Send(1,5,5);		
		}
		delay_ms(50);
		Mouse_Send(0,5,5);
		USB_Send_Key_Press(4, 0);
		delay_ms(20);
		USB_Send_Key_Press(0, 0);
		
		delay_ms(100);
	}
*/


/*
	while(1)
	{		
		GPIOB->ODR|= 1<<8;	
		PBout(8) = 1;
		delay_ms(2000);
		GPIOB->ODR &=~(1<<8);		
		PBout(8) = 0;
		delay_ms(2000);
	}		
	
	while(1)
	{
			Mouse_Send(2,-1,5);
			delay_ms(10);
			Mouse_Send(0,0,0);
			delay_ms(10);
	}
		
	if(EP2BUSY==0)
	{
			EP2BUSY = 1;				
			Joystick_Send(1,10);			
	}
		
	if(EP1BUSY==0)
	{
			EP1BUSY = 1;		
			Joystick_Send(0,0x4);			
	}
*/		




