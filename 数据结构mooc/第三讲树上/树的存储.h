#pragma once
#include <iostream>
using namespace std;



typedef int ElementType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode	
{
	ElementType Data;
	BinTree left;
	BinTree right;
};
//计算数的高度,运用递归后序遍历的变换
int jundgeTree(BinTree bt);
void testTraveral();

void PreOrderTraversal(BinTree BT); //先序遍历
void InOrderTraversal(BinTree BT);	//中序遍历
void PostOrderTraversal(BinTree BT);	//后序遍历

#define MaxSize 1024
typedef BinTree ElementType1;
typedef struct SNode1* Stack1;
struct SNode1 {
	ElementType1 Data[MaxSize];
	int Top;
};

Stack1 createEmptyStack1();
void PushStack1(Stack1 PtrS, ElementType1 item);
ElementType1 PopStack1(Stack1 PtrS);
bool isEmptyStack1(Stack1 PtrS);
bool isFullStack1(Stack1 PtrS);
//中序遍历非递归算法
void InOrderBianli(BinTree bt);

struct  NodeL1
{
	ElementType1 Data;
	struct NodeL1* Next;
};

struct QNodeL1
{
	NodeL1 *rear;
	NodeL1 *front;
};

typedef QNodeL1 * QueueL1;
QueueL1 CreateQueueL1();	//生成长度为maxsize的空队列
void AddQL1(QueueL1 Q, ElementType1 item);	//将数据元素item插入队列Q中
bool IsEmptyQL1(QueueL1 Q);		//判断队列是否为空
ElementType1 DeleteQL1(QueueL1 Q);	//将对头元素从队列中删除并返回
//层序遍历
void CengTraversal(BinTree bt);
