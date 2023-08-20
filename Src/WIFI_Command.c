#include "WIFI_Command.h"

//#define COMM_BRAKE  		'E'//停止
//#define COMM_FORWARD    'A'//前进
//#define COMM_BACK  			'B'//后退
//#define COMM_LEFT  			'C'//左转
//#define COMM_RIGHT 			'D'//右转
//#define COMM_SPIN_LEFT	'F'//左旋转
//#define COMM_SPIN_RIGHT	'G'//右旋转

char receive_command()
{
	char comm=COMM_BRAKE;
	uint8_t reclen=0;
	if(USART2_RX_STA!=0)	//接收到一次数据了
		{
			reclen=USART2_RX_STA&0X7FFF;	//得到数据长度
			USART2_RX[reclen]=0;	 				//加入结束符
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
