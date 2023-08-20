#include "key.h"
#include "main.h"
#include "beeper.h"

//按键位于PC2，按下为高，松开为低
//调用该函数后，系统等待按键输入
//按键期间蜂鸣器鸣响，松开按键后系统继续运行
void keyscan(void)
{
	//没有按下, 空循环等待
	while (KEY==GPIO_PIN_RESET)
	{
	KEY;
	}
	
  while (KEY==GPIO_PIN_SET)
	{
		HAL_Delay(10);
		//按下，延时消抖
		if (KEY==GPIO_PIN_SET)
		{
			BEEPER_SET;
			if (KEY==GPIO_PIN_RESET)
				BEEPER_RESET;
		}
		else
			BEEPER_RESET;
	}
}
