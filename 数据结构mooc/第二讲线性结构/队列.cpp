#include"����.h"

QueueS CreateQueueS(int maxsize)	//���ɳ���Ϊmaxsize�Ŀն���
{
	QueueS q = (QueueS)malloc(maxsize);

	if (q)
	{
		q->front = -1;
		q->rear = -1;
		return q;
	}
}
bool IsFullQS(QueueS Q, int maxsize)	//�ж϶���Q�Ƿ�����
{
	if ((Q->rear-Q->front+maxsize)%maxsize==1)
	{
		return true;
	}
	return false;
}
void AddQS(QueueS Q, ElementType item)	//������Ԫ��item�������Q��
{
	if (IsFullQS(Q,MaxSize))
	{
		cout << "��������" << endl;
		return;
	}
	Q->rear = (Q->rear + 1) % MaxSize;
	Q->Data[Q->rear] = item;

}
bool IsEmptyQS(QueueS Q)		//�ж϶����Ƿ�Ϊ��
{
	if (Q->rear==Q->front)
	{
		return true;
	}
	return false;
}
ElementType DeleteQS(QueueS Q)	//����ͷԪ�شӶ�����ɾ��������
{
	if (IsEmptyQS(Q))
	{
		cout << "�б�Ϊ���޷�ɾ��" << endl;
		return -1;
	}
	ElementType item = Q->Data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return item;

}


QueueL CreateQueueL()
{
	QueueL p = (QueueL)malloc(sizeof(QNodeL));
	p->front = NULL;
	p->rear = NULL;
	return p;
}
void AddQL(QueueL Q, ElementType item)	//������Ԫ��item�������Q��
{
	NodeL* s = (NodeL*)malloc(sizeof(NodeL));
	s->Data = item;
	if (IsEmptyQL(Q))
	{
		Q->front = s;
		Q->rear = s;
	}
	else
	{
		NodeL* p = Q->rear;
		p->Next = s;
		Q->rear = s;
	}
}
bool IsEmptyQL(QueueL Q)		//�ж϶����Ƿ�Ϊ��
{
	return(Q->front == NULL);
}
ElementType DeleteQL(QueueL Q)	//����ͷԪ�شӶ�����ɾ��������
{
	if (IsEmptyQL(Q))
	{
		cout << "����Ϊ�գ�" << endl;
		return -1;
	}
	NodeL* p = Q->front;

	if (Q->front==Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = p->Next;
	}
	ElementType item = p->Data;
	free(p);
	return item;



}
