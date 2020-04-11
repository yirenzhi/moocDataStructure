#pragma once
#include <iostream>
using namespace std;

#define MaxSize 1024
typedef int ElementType;
//#define ElementType int;
typedef struct QNodeS* QueueS;
struct QNodeS {
	ElementType Data[MaxSize];
	int rear;
	int front;
};

QueueS CreateQueueS(int maxsize);	//���ɳ���Ϊmaxsize�Ŀն���
bool IsFullQS(QueueS Q, int maxsize);	//�ж϶���Q�Ƿ�����
void AddQS(QueueS Q, ElementType item);	//������Ԫ��item�������Q��
bool IsEmptyQS(QueueS Q);		//�ж϶����Ƿ�Ϊ��
ElementType DeleteQS(QueueS Q);	//����ͷԪ�شӶ�����ɾ��������

struct  NodeL
{
	ElementType Data;
	struct NodeL* Next;
};

struct QNodeL
{
	NodeL *rear;
	NodeL *front;
};

typedef QNodeL * QueueL;


QueueL CreateQueueL();	//���ɳ���Ϊmaxsize�Ŀն���
void AddQL(QueueL Q, ElementType item);	//������Ԫ��item�������Q��
bool IsEmptyQL(QueueL Q);		//�ж϶����Ƿ�Ϊ��
ElementType DeleteQL(QueueL Q);	//����ͷԪ�شӶ�����ɾ��������
