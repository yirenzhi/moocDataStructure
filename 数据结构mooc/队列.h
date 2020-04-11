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

QueueS CreateQueueS(int maxsize);	//生成长度为maxsize的空队列
bool IsFullQS(QueueS Q, int maxsize);	//判断队列Q是否已满
void AddQS(QueueS Q, ElementType item);	//将数据元素item插入队列Q中
bool IsEmptyQS(QueueS Q);		//判断队列是否为空
ElementType DeleteQS(QueueS Q);	//将对头元素从队列中删除并返回

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


QueueL CreateQueueL();	//生成长度为maxsize的空队列
void AddQL(QueueL Q, ElementType item);	//将数据元素item插入队列Q中
bool IsEmptyQL(QueueL Q);		//判断队列是否为空
ElementType DeleteQL(QueueL Q);	//将对头元素从队列中删除并返回
