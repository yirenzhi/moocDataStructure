#include"队列.h"

QueueS CreateQueueS(int maxsize)	//生成长度为maxsize的空队列
{
	QueueS q = (QueueS)malloc(maxsize);

	if (q)
	{
		q->front = -1;
		q->rear = -1;
		return q;
	}
}
bool IsFullQS(QueueS Q, int maxsize)	//判断队列Q是否已满
{
	if ((Q->rear-Q->front+maxsize)%maxsize==1)
	{
		return true;
	}
	return false;
}
void AddQS(QueueS Q, ElementType item)	//将数据元素item插入队列Q中
{
	if (IsFullQS(Q,MaxSize))
	{
		cout << "队列已满" << endl;
		return;
	}
	Q->rear = (Q->rear + 1) % MaxSize;
	Q->Data[Q->rear] = item;

}
bool IsEmptyQS(QueueS Q)		//判断队列是否为空
{
	if (Q->rear==Q->front)
	{
		return true;
	}
	return false;
}
ElementType DeleteQS(QueueS Q)	//将对头元素从队列中删除并返回
{
	if (IsEmptyQS(Q))
	{
		cout << "列表为空无法删除" << endl;
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
void AddQL(QueueL Q, ElementType item)	//将数据元素item插入队列Q中
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
bool IsEmptyQL(QueueL Q)		//判断队列是否为空
{
	return(Q->front == NULL);
}
ElementType DeleteQL(QueueL Q)	//将对头元素从队列中删除并返回
{
	if (IsEmptyQL(Q))
	{
		cout << "队列为空：" << endl;
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
