
#include "keyscanner.h"
#include "delay.h"	
#include "sys.h"

u16 KEY_MAP[8][16] = {
	/*	     Left  -     Right Down  / ?               N     Space  B          RAlt                   */
		{0x00, 0x50, 0x56, 0x4F, 0x51, 0x38, 0x00, 0x00, 0x11, 0x2C, 0x05, 0x00, 0xE6, 0x00, 0x00, 0x00},
	/*	     Pause *     /     Num         . >   , <   M     Enter V     C     X     Z     RShft RCtl */
		{0x00, 0x48, 0x55, 0x54, 0x53, 0x00, 0x37, 0x36, 0x10, 0x28, 0x19, 0x06, 0x1B, 0x1D, 0xE5, 0xE4},
	/*	     EntKP 3 KP  2 KP  1 KP  ; :   L     K     J     \ |   F     D     S     A              */
		{0x00, 0x58, 0x5B, 0x5A, 0x59, 0x33, 0x0F, 0x0E, 0x0D, 0x31, 0x09, 0x07, 0x16, 0x04, 0x00, 0x00},
	/* SLk   + KP  9 KP  8 KP  7 KP  P     O     I     U           R     E     W     Q              */
		{0x47, 0x57, 0x61, 0x60, 0x5F, 0x13, 0x12, 0x0C, 0x18, 0x00, 0x15, 0x08, 0x1A, 0x14, 0x00, 0x00},
	/* PSc   End   PgDn  F12   F11   0 )   9 (   8 *   7 &   F10   4 $   3 #   2 @   1 !            */
		{0x46, 0x4D, 0x4E, 0x45, 0x44, 0x27, 0x26, 0x25, 0x24, 0x43, 0x21, 0x20, 0x1F, 0x1E, 0x00, 0x00},
	/*	 	   Home  PgUp  Ins   Del   - _   F8    = +   6 ^   F9    5 %   F2    F1    ` ~         LCtl */
		{0x00, 0x4A, 0x4B, 0x49, 0x4C, 0x2D, 0x41, 0x2E, 0x23, 0x42, 0x22, 0x3B, 0x3A, 0x35, 0x00, 0xE0},
	/*  	         6 KP  5 KP  4 KP  [ {   F7    ] }    Y    Bsp   T     F3    Caps  Tab   LShft      */
		{0x00, 0x00, 0x5E, 0x97, 0x5C, 0x2F, 0x40, 0x30, 0x1C, 0x2A, 0x17, 0x3C, 0x39, 0x2B, 0xE1, 0x00},
	/*  	   Up                      ' "         F6    H     F5    G     4     LAlt  ESC   DelKP 0 KP */
		{0x00, 0x52, 0x00, 0x00, 0x00, 0x34, 0x00, 0x3F, 0x0B, 0x3E, 0x0A, 0x3D, 0xE2, 0x29, 0x63, 0x62}
};



//       0      1      2      3      4      5      6      7         8      9      a      b      c      d      e      f
//0x0X
//high 2bit.(4,8)
//01: RGUI RALT RSHIFT RCTRL LGUI LALT LSHIFT LCTRL
//10: media key

// RGUI                            0x4007
// RALT                            0x4006
// RSHIFT                          0x4005
// RCTRL                           0x4004
// LGUI                            0x4003
// LALT                            0x4002
// LSHIFT                          0x4001
// LCTRL                           0x4000
// Mute                            0x80e2
// Volume Up                       0x80e9
// Volume Down                     0x80ea
// Tracking Increment              0x80b5
// Tracking Decrement              0x80b6
// Stop/Eject                      0x80b7
// Play/Pause                      0x80cd
// AC Forward                      0x8225
// AC Back                         0x8224
// AL Calculator                   0x8192
/*
u32 KEY_MAP2[8][16] = {
//0x0x   N               Space           B       / ?             Down            Right    LWIN   AC_Ford         Left            RALT
       { 0x0011 ,0xffff	,0x002c	,0xffff	,0x0005	,0x0038	,0xffff ,0x0051 ,0xffff ,0x004f ,0x4003 ,0x8225 ,0xffff ,0x0050 ,0xffff ,0x4006},
//0x2X   7 &     8 *     F10     9 (     4 $     0 )     3 #    F11      2 @     F12     1 !     PgDn            End             PSc
       { 0x0024 ,0x0025 ,0x0043 ,0x0026 ,0x0021 ,0x0027 ,0x0020 ,0x0044 ,0x001f ,0x0045 ,0x001e ,0x004e ,0xffff ,0x004d ,0xffff ,0x0046},
//0x1X   M  		 , <     Enter   . >     V               C               X               Z       AC_BACK RSHIFT  Pause   RCTRL
       { 0x0010 ,0x0036 ,0x0028 ,0x0037 ,0x0019 ,0xffff ,0x0006 ,0xffff ,0x001b ,0xffff ,0x001d ,0x8224 ,0x4005 ,0x0048 ,0x4004 ,0xffff},
//0x3X   J       K       \ |     L       F       ; :     D       mute    S               A       Appkey
       { 0x000d ,0x000e ,0x0031 ,0x000f ,0x0009 ,0x0033 ,0x0007 ,0x80e2 ,0x0016 ,0xffff ,0x0004 ,0x0065 ,0xffff ,0xffff ,0xffff ,0xffff},
//0x4X   U       I               O       R       P       E       vol_up  W               Q       LWIN                            SLk 
       { 0x0018 ,0x000c ,0xffff ,0x0012 ,0x0015 ,0x0013 ,0x0008 ,0x80e9 ,0x001a ,0xffff ,0x0014 ,0x4003 ,0xffff ,0xffff ,0xffff ,0x0047},
//0x5X   Y       ] }     Bsp     F7      T       [ {     F3      vol_dn  Caps    LWIN    Tab             LSHIFT
       { 0x001c ,0x0030 ,0x002a ,0x0040 ,0x0017 ,0x002f ,0x003c ,0x80ea ,0x0039 ,0x4003 ,0x002b ,0xffff ,0x4001 ,0xffff ,0xffff ,0xffff},
//0x6X   6 ^     = +     F9      F8      5 %     - _     F2      Del     F1      Ins     ` ~     PgUp            Home    LCTRL
       { 0x0023 ,0x002e ,0x0042 ,0x0041 ,0x0022 ,0x002d ,0x003b ,0x004c ,0x003a ,0x0049 ,0x0035 ,0x004b ,0xffff ,0x004a ,0x4000 ,0xffff},
//0x7X   H       F6      F5              G       ' "     F4                               ESC                     Up              LALT
       { 0x000b ,0x003f ,0x003e ,0xffff ,0x000a ,0x0034 ,0x003d ,0xffff ,0xffff ,0xffff ,0x0029 ,0xffff ,0xffff ,0x0052 ,0xffff ,0x4002}			 
};
*/

u32 KEY_MAP1[8][16]={
//0x0x           Down    B       / ?     Space           N               Right           AC_Ford  LWIN   Left           RALT             
       { 0xffff ,0x0051 ,0x0005	,0x0038	,0x002c	,0xffff	,0x0011 ,0xffff	,0x004f ,0xffff ,0x8225 ,0x4003 ,0x0050,0xffff ,0x4006 ,0xffff },
//0x2X   3 #    F11      4 $     0 )     F10     9 (     7 &     8 *     F12     2 @     PgDn    1 !     End            PSc              
       { 0x0020 ,0x0044 ,0x0021 ,0x0027 ,0x0043 ,0x0026 ,0x0024 ,0x0025 ,0x0045 ,0x001f ,0x004e ,0x001e ,0x004d,0xffff ,0x0046 ,0xffff },
//0x1X   C               V               Enter   . >     M  		 , <             X       AC_BACK Z       Pause  RSHIFT          RCTRL    
       { 0x0006 ,0xffff ,0x0019 ,0xffff ,0x0028 ,0x0037 ,0x0010 ,0x0036 ,0xffff ,0x001b ,0x8224 ,0x001d ,0x0048,0x4005 ,0xffff ,0x4004 },
//0x3X   D       mute    F       ; :     \ |     L       J       K               S       Appkey  A                                       
       { 0x0007 ,0x80e2 ,0x0009 ,0x0033 ,0x0031 ,0x000f ,0x000d ,0x000e ,0xffff ,0x0016 ,0x0065 ,0x0004 ,0xffff,0xffff ,0xffff ,0xffff },
//0x4X   E       vol_up  R       P               O       U       I               W       LWIN    Q                      SLk              
       { 0x0008 ,0x80e9 ,0x0015 ,0x0013 ,0xffff ,0x0012 ,0x0018 ,0x000c ,0xffff ,0x001a ,0x4003 ,0x0014 ,0xffff,0xffff ,0x0047 ,0xffff },
//0x5X   F3      vol_dn  T       [ {     Bsp     F7      Y       ] }     LWIN    Caps            Tab            LSHIFT                   
       { 0x003c ,0x80ea ,0x0017 ,0x002f ,0x002a ,0x0040 ,0x001c ,0x0030 ,0x4003 ,0x0039 ,0xffff ,0x002b ,0xffff,0x4001 ,0xffff ,0xffff },
//0x6X   F2      Del     5 %     - _     F9      F8      6 ^     = +     Ins     F1      PgUp    ` ~     Home                   LCTRL    
       { 0x003b ,0x004c ,0x0022 ,0x002d ,0x0042 ,0x0041 ,0x0023 ,0x002e ,0x0049 ,0x003a ,0x004b ,0x0035 ,0x004a,0xffff ,0xffff ,0x4000 },
//0x7X   F4              G       ' "     F5              H       F6                               ESC     Up             LALT            
       { 0x003d ,0xffff ,0x000a ,0x0034 ,0x003e ,0xffff ,0x000b ,0x003f ,0xffff ,0xffff ,0xffff ,0x0029 ,0x0052,0xffff ,0x4002 ,0xffff }	
};                                                                                                                                                                                                                                                                                                                                                                                                 

u32 KEY_MAP2[8][16]={
//0x0x            N               Space   / ?     B       Down            Right           AC_Ford  LWIN   Left           RALT             
       {0xffff	, 0x0011 ,0xffff	,0x002c	,0x0038	,0x0005	,0x0051 ,0xffff ,0x004f ,0xffff ,0x8225 ,0x4003 ,0x0050,0xffff ,0x4006 ,0xffff },
//0x2X  8 *       7 &     9 (     F10     0 )     4 $     11      3 #    FF12     2 @     PgDn    1 !     End            PSc              
       {0x0025 ,  0x0024 ,0x0026 ,0x0043 ,0x0027 ,0x0021 ,0x0044 ,0x0020 ,0x0045 ,0x001f ,0x004e ,0x001e ,0x004d,0xffff ,0x0046 ,0xffff },
//0x1X  , <       M  		 . >     Enter           V               C               X       AC_BACK Z       Pause  RSHIFT          RCTRL    
       {0x0036 ,  0x0010 ,0x0037 ,0x0028 ,0xffff ,0x0019 ,0xffff ,0x0006 ,0xffff ,0x001b ,0x8224 ,0x001d ,0x0048,0x4005 ,0xffff ,0x4004 },
//0x3X  K         J       L       \ |     ; :     F       mute    D               S       Appkey  A                                       
       {0x000e ,  0x000d ,0x000f ,0x0031 ,0x0033 ,0x0009 ,0x80e2 ,0x0007 ,0xffff ,0x0016 ,0x0065 ,0x0004 ,0xffff,0xffff ,0xffff ,0xffff },
//0x4X  I         U       O               P       R       vol_up  E               W       LWIN    Q                      SLk              
       {0x000c ,  0x0018 ,0x0012 ,0xffff ,0x0013 ,0x0015 ,0x80e9 ,0x0008 ,0xffff ,0x001a ,0x4003 ,0x0014 ,0xffff,0xffff ,0x0047 ,0xffff },
//0x5X  ] }       Y       F7      Bsp     [ {     T       vol_dn  F3      LWIN    Caps            Tab            LSHIFT                   
       {0x0030 ,  0x001c ,0x0040 ,0x002a ,0x002f ,0x0017 ,0x80ea ,0x003c ,0x4003 ,0x0039 ,0xffff ,0x002b ,0xffff,0x4001 ,0xffff ,0xffff },
//0x6X  = +       6 ^     F8      F9      - _     5 %     Del     F2      Ins     F1      PgUp    ` ~     Home                   LCTRL    
       {0x002e ,  0x0023 ,0x0041 ,0x0042 ,0x002d ,0x0022 ,0x004c ,0x003b ,0x0049 ,0x003a ,0x004b ,0x0035 ,0x004a,0xffff ,0xffff ,0x4000 },
//0x7X  F6        H               F5      ' "     G               F4                               ESC     Up             LALT            
       {0x003f ,  0x000b ,0xffff ,0x003e ,0x0034 ,0x000a ,0xffff ,0x003d ,0xffff ,0xffff ,0xffff ,0x0029 ,0x0052,0xffff ,0x4002 ,0xffff }	
};                                                                                                                                                                                                                                                                                                                                                                                                 

// private functions
uint16_t KS_ScanForKeyPress(uint16_t iActiveLine);
uint16_t KS_ScanForKeyPress_2(uint16_t iActiveLine);
uint16_t KS_ScanForKeyPress_3(uint16_t iActiveLine);
uint8_t KS_IsModifier(uint16_t scanCode);
void KS_UpdateModifiers(uint16_t scanCode, uint8_t* modifiers);
void KS_GpioPinInit(GPIO_TypeDef *iPort, uint32_t iPin, uint32_t iMode, uint32_t iPull, uint32_t iSpeed);


#define  PIN_CLK  1<<3  //PB3
#define  PIN_DATA 1<<4  //PB4

void KS_Init()
{
	// remap JTAG to GPIO, leaving SWD enabled
	//__HAL_AFIO_REMAP_SWJ_NOJTAG();
	
	// init input scan lines
	// PB 3,4  clock  data
	// PA 1,2,3,4,5,6,7 sacn line
	GPIOA->CRL  = 0X88888888;    //intput ,08 输入 
	GPIOA->ODR |= 0X00000000;    //intput ,08 下拉 
	
	GPIOA->CRH &= 0XFFFFFF00;    //output ,03
	GPIOA->CRH |= 0X00000033;    //output ,03 输出
	
	GPIOB->CRL  = 0X22222227;    //output ,02 2M输出 
	GPIOB->CRH  = 0X22222227;    //output ,02 2M输出
}
// 测试用
uint16_t KS_ScanForKeyPress_3(uint16_t iActiveLine)
{
	uint8_t scannedInput ;
	GPIOB->ODR = iActiveLine;	
	scannedInput = (uint8_t)GPIOA->IDR;
	return scannedInput;
}

// 测试用
uint16_t KS_ScanForKeyPress_2(uint16_t iActiveLine)
{
	uint8_t scannedInput ;
	if (iActiveLine==1)
	{
		GPIOA->BSRR = PIN_DATA;
		GPIOA->BRR = PIN_CLK;
	}
	else
	{
		GPIOA->BRR = PIN_DATA;
		GPIOA->BSRR = PIN_CLK;
	}// get the scan result;
	scannedInput = (uint8_t)GPIOA->IDR;
	return scannedInput;
}

uint16_t KS_ScanForKeyPress_4(uint16_t iActiveLine)
{
	uint8_t i;
	uint8_t scannedInput ;
	
	// 一共16位
	for ( i = 0 ; i < 16 ; i++)
	{	
		if ( (( iActiveLine >> i) & 0x01 ) == 1)
			GPIOB->BSRR = PIN_DATA;
		else
			GPIOB->BRR = PIN_DATA;
		delay_us(20);
		
		GPIOB->BSRR = PIN_CLK;
		delay_us(20);
		GPIOB->BRR = PIN_CLK;
		delay_us(20);
	}
	
	GPIOB->BSRR = PIN_CLK;
	delay_us(20);
	GPIOB->BRR = PIN_CLK;
	delay_us(20);
		
	// get the scan result;
	scannedInput = (uint8_t)GPIOA->IDR;
	return scannedInput;
}

#ifdef DEBUG
void KS_PrintScanLines()
{
	uint16_t scannedInput;
	uint8_t keyScans = 0;
	uint8_t i;
	for(i = 0; i < 8; ++i)
	{
		scannedInput = KS_ScanForKeyPress(1 << (7 - i));
		if (scannedInput > 0)
		{
			// detected a key press
			printf("Key press detected at %d/0x%04X\n", (i+1), scannedInput);
			++keyScans;
		}
	}
}
#else
void KS_PrintScanLines() {}
#endif

uint8_t KS_ReadScanCode(uint8_t* scanCodeBuffer, uint8_t bufferLength, uint8_t* modifiers)
{
	uint16_t scannedInput;
	uint8_t keyStrokes = 0;
	uint16_t scanCode;
	uint8_t i;
	uint8_t j;
	// 16 driver lines
	for(i = 0; i < 16; i++)	
	{
		//set the drive line to low. example , 1111011111111111
	  //scannedInput = KS_ScanForKeyPress(~(1 << (0x0F - i)));
		scannedInput = KS_ScanForKeyPress_4((1 << (i)));			
		if (scannedInput == 0x00) 
			continue;
		// 8  scan lines
		for(j = 0; j < 8; j++)
		{
			// decode detected a key press(es) //low level
			if (((scannedInput >> j) & 0x0001) == 1)
			{
				scanCode = KEY_MAP1[7-j][15 - i];
				if (scanCode != 0xFFFF)
				{
					if (KS_IsModifier(scanCode))
					{
						KS_UpdateModifiers(scanCode, modifiers);
					}
					else if (keyStrokes < bufferLength)
					{
						keyStrokes++;						
						scanCodeBuffer[keyStrokes - 1] = scanCode;
					}
				}
				else
				{
;//					printf("No key-code found for scanned key: %i/%i (scanned input line was 0x%04X\n", i, (0x0F - j), scannedInput);
				}
			}
		}
	}
	return keyStrokes;
}

uint8_t KS_IsModifier(uint16_t scanCode)
{
	if (scanCode >= 0x4000 && scanCode < 0x400F)
		return 1==1;
		
	switch(scanCode)
	{
		case 0xE0:
		case 0xE1:
		case 0xE2:
		case 0xE3:
		case 0xE4:
		case 0xE5:
		case 0xE6:
		case 0xE7:
			return 1==1;
		default:
			return 1==0;
	}
}

void KS_UpdateModifiers(uint16_t scanCode, uint8_t* modifiers)
{
	*modifiers |= 1 << (uint8_t)(0x000F & scanCode);
}

void KS_GpioPinInit(GPIO_TypeDef *iPort, uint32_t iPin, uint32_t iMode, uint32_t iPull, uint32_t iSpeed)
{
	// Initialize the port and the pin
	/*
	GPIO_InitTypeDef   GPIO_InitStructure;
	GPIO_InitStructure.Pin = iPin;
	GPIO_InitStructure.Mode = iMode;
	GPIO_InitStructure.Pull = iPull;
	GPIO_InitStructure.Speed = iSpeed;
	HAL_GPIO_Init( iPort, &GPIO_InitStructure );
	*/
}

