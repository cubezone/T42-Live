#include "keyboard.h"
#include "usart.h"
//#include "lcd.h"

u8 KEYBOARD_ID1,KEYBOARD_ID2;
u16 KEYBOARD_COUNT;
//处理KEYBOARD的数据，键盘控制符到ASCII码的映射关系	 
void Keyboard_Data_Pro(u16 index)
{			    			    
	u16 x_count,y_count;
	if(PS2_DATA_BUF[0]==PS2_DATA_BUF[2])  //键盘模式下，会接收到三个字节：例如‘A’,MCU会接收到十六进制数1C,F0,1C。
	{
		x_count=index%30;	 //打印在液晶屏上显示，x分行
		y_count=index/30;	 //打印在液晶屏上显示，y分列
		switch(PS2_DATA_BUF[0])
		{
			case 0x1C:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'A',16,1); //键盘控制符到ASCII码的映射关系
				break;
			case 0x32:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'B',16,1);
				break;
			case 0x21:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'C',16,1);
				break;
			case 0x23:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'D',16,1);
				break;
			case 0x24:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'E',16,1);
				break;
			case 0x2B:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'F',16,1);
				break;
			case 0x34:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'G',16,1);
				break;
			case 0x33:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'H',16,1);
				break;
			case 0x43:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'I',16,1);
				break;
			case 0x3B:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'J',16,1);
				break;
			case 0x42:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'K',16,1);
				break;
			case 0x4B:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'L',16,1);
				break;
			case 0x3A:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'M',16,1);
				break;
			case 0x31:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'N',16,1);
				break;
			case 0x44:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'O',16,1);
				break;
			case 0x4D:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'P',16,1);
				break;
			case 0x15:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'Q',16,1);
				break;
			case 0x2D:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'R',16,1);
				break;
			case 0x1B:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'S',16,1);
				break;
			case 0x2C:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'T',16,1);
				break;
			case 0x3C:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'U',16,1);
				break;
			case 0x2A:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'V',16,1);
				break;
			case 0x1D:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'W',16,1);
				break;
			case 0x22:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'X',16,1);
				break;
			case 0x35:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'Y',16,1);
				break;
			case 0x1A:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'Z',16,1);
				break;
			case 0x45:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'0',16,1);
				break;
			case 0x16:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'1',16,1);
				break;
			case 0x1E:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'2',16,1);
				break;
			case 0x26:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'3',16,1);
				break;
			case 0x25:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'4',16,1);
				break;
			case 0x2E:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'5',16,1);
				break;
			case 0x36:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'6',16,1);
				break;
			case 0x3D:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'7',16,1);
				break;
			case 0x3E:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'8',16,1);
				break;
			case 0x46:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'9',16,1);
				break;
			case 0x0E:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'`',16,1);
				break;
			case 0x4E:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'-',16,1);
				break;
			case 0x55:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'=',16,1);
				break;
			case 0x5D:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,92,16,1);	  //为何这个有问题:'\'
				break;
			case 0x54:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'[',16,1);
				break;
			case 0x5B:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,']',16,1);
				break;
			case 0x4C:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,';',16,1);
				break;
			case 0x52:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,39,16,1);   //为何这个有问题:'''
				break;
			case 0x41:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,',',16,1);
				break;
			case 0x49:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'.',16,1);
				break;
			case 0x4A:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'/',16,1);
				break;
		}
	} 
}	 

//初始化键盘
//返回:0,初始化成功
//其他:错误代码
//CHECK OK 2011/11/20/10:37
u8 Init_Keyboard(void)
{
	u8 t;		 
	PS2_Init();							     
	delay_ms(800);            //等待上电复位完成		 	 
	PS2_Status=CMDMODE;       //进入命令模式
	t=PS2_Send_Cmd(RESET); //复位键盘		 
	if(t!=0)return 1;
	t=PS2_Get_Byte();			  
    if(t!=0XFA)return 2;
	t=0;
	while((PS2_Status&0x80)==0)//等待复位完毕 
	{
		t++;
		delay_ms(10);      
		if(t>50)return 3;
	}
	PS2_Get_Byte();//得到0XAA		 
	//进入键盘模式的特殊初始化序列
	
	PS2_Send_Cmd(Set_Reset_LEDs);       	//引起键盘进入"Reset"模式
    if(PS2_Get_Byte()!=0XFA)return 4;   	//传输失败
	PS2_Send_Cmd(0X00);						//关闭指示键盘上Num Lock, Caps Lock, and Scroll Lock LED
    if(PS2_Get_Byte()!=0XFA)return 5;   	//传输失败
	PS2_Send_Cmd(Read_ID);					//键盘回应两个字节的设备ID,0xAB,0X83
    if(PS2_Get_Byte()!=0XFA)return 6;   	//传输失败
	KEYBOARD_ID1=PS2_Get_Byte();			//设备KEYBOARD_ID1,0xAB
	KEYBOARD_ID2=PS2_Get_Byte();			//设备KEYBOARD_ID2,0X83
	PS2_Send_Cmd(Set_Reset_LEDs);       	//引起键盘进入"Reset"模式
    if(PS2_Get_Byte()!=0XFA)return 7;   	//传输失败
	PS2_Send_Cmd(0X02);						//点亮指示键盘上Num Lock灯
    if(PS2_Get_Byte()!=0XFA)return 8;   	//传输失败
	PS2_Send_Cmd(Set_Typematic_Rate_Delay); //定义机打速率和延时
    if(PS2_Get_Byte()!=0XFA)return 9;		//传输失败
	PS2_Send_Cmd(0X20);						//机打速率和延时：30.0 reports/sec 、500 ms 
    if(PS2_Get_Byte()!=0XFA)return 10;		//传输失败
	PS2_Send_Cmd(Enable);					//使能键盘
    if(PS2_Get_Byte()!=0XFA)return 11;		//传输失败
	PS2_Send_Cmd(Set_Typematic_Rate_Delay); //定义机打速率和延时
    if(PS2_Get_Byte()!=0XFA)return 12;		//传输失败
	PS2_Send_Cmd(0X17);						//机打速率和延时：15.0 reports/sec 、250 ms
    if(PS2_Get_Byte()!=0XFA)return 13;		//传输失败

	PS2_Status=KEYBOARD;//进入键盘模式
	return 0;//无错误,初始化成功   
}

