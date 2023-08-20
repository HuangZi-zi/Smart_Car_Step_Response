#include "WIFI_Command.h"

//#define COMM_BRAKE  		'E'//ֹͣ
//#define COMM_FORWARD    'A'//ǰ��
//#define COMM_BACK  			'B'//����
//#define COMM_LEFT  			'C'//��ת
//#define COMM_RIGHT 			'D'//��ת
//#define COMM_SPIN_LEFT	'F'//����ת
//#define COMM_SPIN_RIGHT	'G'//����ת

char receive_command()
{
	char comm=COMM_BRAKE;
	uint8_t reclen=0;
	if(USART2_RX_STA!=0)	//���յ�һ��������
		{
			reclen=USART2_RX_STA&0X7FFF;	//�õ����ݳ���
			USART2_RX[reclen]=0;	 				//���������
//			printf("%s!\n",USART2_RX);
//			printf("%d!\n",reclen);
			if(reclen==1)
			{	
				comm = USART2_RX[0];
				USART2_RX_STA=0;
				memset(USART2_RX,0,sizeof(USART2_RX));
			}
		}	
	return comm;	
}
