#include "key.h"
#include "main.h"
#include "beeper.h"

//����λ��PC2������Ϊ�ߣ��ɿ�Ϊ��
//���øú�����ϵͳ�ȴ���������
//�����ڼ���������죬�ɿ�������ϵͳ��������
void keyscan(void)
{
	//û�а���, ��ѭ���ȴ�
	while (KEY==GPIO_PIN_RESET)
	{
	KEY;
	}
	
  while (KEY==GPIO_PIN_SET)
	{
		HAL_Delay(10);
		//���£���ʱ����
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
