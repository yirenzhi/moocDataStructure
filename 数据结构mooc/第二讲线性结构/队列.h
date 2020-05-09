#pragma once
#include "../base.h"

typedef struct QNodeS* QueueS;
typedef int ElementType;


QueueS CreateQueueS(int maxsize);	//���ɳ���Ϊmaxsize�Ŀն���
bool IsFullQS(QueueS Q, int maxsize);	//�ж϶���Q�Ƿ�����
void AddQS(QueueS Q, ElementType item);	//������Ԫ��item�������Q��
bool IsEmptyQS(QueueS Q);		//�ж϶����Ƿ�Ϊ��
ElementType DeleteQS(QueueS Q);	//����ͷԪ�شӶ�����ɾ��������



typedef QNodeL * QueueL;


QueueL CreateQueueL();	//���ɳ���Ϊmaxsize�Ŀն���
void AddQL(QueueL Q, ElementType item);	//������Ԫ��item�������Q��
bool IsEmptyQL(QueueL Q);		//�ж϶����Ƿ�Ϊ��
ElementType DeleteQL(QueueL Q);	//����ͷԪ�شӶ�����ɾ��������
