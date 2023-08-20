#include "IR_Tracing.h"
#include "main.h"
#include "motor.h"

char ctrl_comm = COMM_BRAKE;			//����ָ��
char ctrl_comm_last = COMM_BRAKE;	//��һ�ε�ָ��


char TracingRun(void)
{
  //����˫��
	//�װ� ֱ��
	if(READ_TRACING_L==WHITE_AREA && READ_TRACING_R==WHITE_AREA)
		ctrl_comm = COMM_FORWARD;
	//�ڰ� ��ת
	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_R == WHITE_AREA)
		ctrl_comm = COMM_SPIN_RIGHT;
	//�׺� ��ת
	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_R == BLACK_AREA)
		ctrl_comm = COMM_SPIN_LEFT;
	else ctrl_comm = COMM_BRAKE;
	
////�м䵥��
//	//�׺ڰ� ֱ��
//	if(READ_TRACING_L==WHITE_AREA && READ_TRACING_M==BLACK_AREA && READ_TRACING_R==WHITE_AREA)
//		ctrl_comm = COMM_FORWARD;
//	//�ڰװ� ��ת
//	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_M == WHITE_AREA && READ_TRACING_R == WHITE_AREA)
//		ctrl_comm = COMM_LEFT;
//	//�װ׺� ��ת
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == WHITE_AREA & READ_TRACING_L == BLACK_AREA)
//		ctrl_comm = COMM_RIGHT;
//	//�װװ� ����
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == WHITE_AREA & READ_TRACING_L == WHITE_AREA)
//		ctrl_comm = COMM_BACK;
//	//�׺ں� ��ת
//	else if (READ_TRACING_L == WHITE_AREA && READ_TRACING_M == BLACK_AREA & READ_TRACING_L == BLACK_AREA)
//		ctrl_comm = COMM_RIGHT;
//	//�ںڰ� ��ת
//	else if (READ_TRACING_L == BLACK_AREA && READ_TRACING_M == BLACK_AREA & READ_TRACING_L == WHITE_AREA)
//		ctrl_comm = COMM_LEFT;
//	else ctrl_comm = COMM_BRAKE;
	if(ctrl_comm_last != ctrl_comm)
	{
			ctrl_comm_last = ctrl_comm;
	}
	return ctrl_comm;
}
