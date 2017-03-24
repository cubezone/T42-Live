#include "keyboard.h"
#include "usart.h"
//#include "lcd.h"

u8 KEYBOARD_ID1,KEYBOARD_ID2;
u16 KEYBOARD_COUNT;
//����KEYBOARD�����ݣ����̿��Ʒ���ASCII���ӳ���ϵ	 
void Keyboard_Data_Pro(u16 index)
{			    			    
	u16 x_count,y_count;
	if(PS2_DATA_BUF[0]==PS2_DATA_BUF[2])  //����ģʽ�£�����յ������ֽڣ����确A��,MCU����յ�ʮ��������1C,F0,1C��
	{
		x_count=index%30;	 //��ӡ��Һ��������ʾ��x����
		y_count=index/30;	 //��ӡ��Һ��������ʾ��y����
		switch(PS2_DATA_BUF[0])
		{
			case 0x1C:
				//LCD_ShowChar(x_count*8,(y_count+1)*16,'A',16,1); //���̿��Ʒ���ASCII���ӳ���ϵ
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
				//LCD_ShowChar(x_count*8,(y_count+1)*16,92,16,1);	  //Ϊ�����������:'\'
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
				//LCD_ShowChar(x_count*8,(y_count+1)*16,39,16,1);   //Ϊ�����������:'''
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

//��ʼ������
//����:0,��ʼ���ɹ�
//����:�������
//CHECK OK 2011/11/20/10:37
u8 Init_Keyboard(void)
{
	u8 t;		 
	PS2_Init();							     
	delay_ms(800);            //�ȴ��ϵ縴λ���		 	 
	PS2_Status=CMDMODE;       //��������ģʽ
	t=PS2_Send_Cmd(RESET); //��λ����		 
	if(t!=0)return 1;
	t=PS2_Get_Byte();			  
    if(t!=0XFA)return 2;
	t=0;
	while((PS2_Status&0x80)==0)//�ȴ���λ��� 
	{
		t++;
		delay_ms(10);      
		if(t>50)return 3;
	}
	PS2_Get_Byte();//�õ�0XAA		 
	//�������ģʽ�������ʼ������
	
	PS2_Send_Cmd(Set_Reset_LEDs);       	//������̽���"Reset"ģʽ
    if(PS2_Get_Byte()!=0XFA)return 4;   	//����ʧ��
	PS2_Send_Cmd(0X00);						//�ر�ָʾ������Num Lock, Caps Lock, and Scroll Lock LED
    if(PS2_Get_Byte()!=0XFA)return 5;   	//����ʧ��
	PS2_Send_Cmd(Read_ID);					//���̻�Ӧ�����ֽڵ��豸ID,0xAB,0X83
    if(PS2_Get_Byte()!=0XFA)return 6;   	//����ʧ��
	KEYBOARD_ID1=PS2_Get_Byte();			//�豸KEYBOARD_ID1,0xAB
	KEYBOARD_ID2=PS2_Get_Byte();			//�豸KEYBOARD_ID2,0X83
	PS2_Send_Cmd(Set_Reset_LEDs);       	//������̽���"Reset"ģʽ
    if(PS2_Get_Byte()!=0XFA)return 7;   	//����ʧ��
	PS2_Send_Cmd(0X02);						//����ָʾ������Num Lock��
    if(PS2_Get_Byte()!=0XFA)return 8;   	//����ʧ��
	PS2_Send_Cmd(Set_Typematic_Rate_Delay); //����������ʺ���ʱ
    if(PS2_Get_Byte()!=0XFA)return 9;		//����ʧ��
	PS2_Send_Cmd(0X20);						//�������ʺ���ʱ��30.0 reports/sec ��500 ms 
    if(PS2_Get_Byte()!=0XFA)return 10;		//����ʧ��
	PS2_Send_Cmd(Enable);					//ʹ�ܼ���
    if(PS2_Get_Byte()!=0XFA)return 11;		//����ʧ��
	PS2_Send_Cmd(Set_Typematic_Rate_Delay); //����������ʺ���ʱ
    if(PS2_Get_Byte()!=0XFA)return 12;		//����ʧ��
	PS2_Send_Cmd(0X17);						//�������ʺ���ʱ��15.0 reports/sec ��250 ms
    if(PS2_Get_Byte()!=0XFA)return 13;		//����ʧ��

	PS2_Status=KEYBOARD;//�������ģʽ
	return 0;//�޴���,��ʼ���ɹ�   
}

