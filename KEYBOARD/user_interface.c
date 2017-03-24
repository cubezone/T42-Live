
#include "user_interface.h"

void UserInterface_Init(void)
{


	UserInterface_Led_All_Off();
}


void UserInterface_Led_On(UserInterface_LedType led)
{
	if (led == CAPS_LOCK)
	{
	//	HAL_GPIO_WritePin(LED_PORT, CAPS_LOCK_PIN, GPIO_PIN_RESET);
	}
	else if (led == SCROLL_LOCK)
	{
		//HAL_GPIO_WritePin(LED_PORT, SCROLL_LOCK_PIN, GPIO_PIN_RESET);
	}
	else if (led == NUM_LOCK)
	{
	//	HAL_GPIO_WritePin(LED_PORT, NUM_LOCK_PIN, GPIO_PIN_RESET);
	}
}

void UserInterface_Led_Off(UserInterface_LedType led)
{
	if (led == CAPS_LOCK)
	{
		HAL_GPIO_WritePin(LED_PORT, CAPS_LOCK_PIN, GPIO_PIN_SET);
	}
	else if (led == SCROLL_LOCK)
	{
		HAL_GPIO_WritePin(LED_PORT, SCROLL_LOCK_PIN, GPIO_PIN_SET);
	}
	else if (led == NUM_LOCK)
	{
		HAL_GPIO_WritePin(LED_PORT, NUM_LOCK_PIN, GPIO_PIN_SET);
	}
}


void UserInterface_Led_All_Off()
{
	UserInterface_Led_Off(CAPS_LOCK);
	UserInterface_Led_Off(SCROLL_LOCK);
	UserInterface_Led_Off(NUM_LOCK);
}

void UserInterface_Led_Set(UserInterface_LedType led, uint8_t state)
{
	if (state == 0)
	{
		UserInterface_Led_Off(led);
	}
	else
	{
		UserInterface_Led_On(led);
	}
}
