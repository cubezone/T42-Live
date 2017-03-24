
#include "usb_keyboard.h"
#include "hw_config.h"

void USB_Send_Key_Press(char c, uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;
	report[index++] = modifier;
	report[index++] = 0x00;
	report[index++] = (uint8_t)c;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	
	keyboard_Send(modifier,c);
	
	//USBD_HID_SendReport(&hUsbDeviceFS, report, index);
}

void USB_Send_Key_Release(char c, uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;
	report[index++] = modifier;
	report[index++] = 0x00;
	report[index++] = (uint8_t)c;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	
  Joystick_Send(0,c);
	//USBD_HID_SendReport(&hUsbDeviceFS, report, index);
}

void USB_Send_All_Keys_Released(uint8_t modifier)
{
	uint8_t report[9];
	uint8_t index = 0;
	report[index++] = modifier;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	report[index++] = 0x00;
	
	Joystick_Send(0,0x00);
//	USBD_HID_SendReport(&hUsbDeviceFS, report, index);
}
