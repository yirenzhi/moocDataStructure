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
//�������ĸ߶�,���õݹ��������ı任
int jundgeTree(BinTree bt);
void testTraveral();

void PreOrderTraversal(BinTree BT); //�������
void InOrderTraversal(BinTree BT);	//�������
void PostOrderTraversal(BinTree BT);	//�������

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
//��������ǵݹ��㷨
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
QueueL1 CreateQueueL1();	//���ɳ���Ϊmaxsize�Ŀն���
void AddQL1(QueueL1 Q, ElementType1 item);	//������Ԫ��item�������Q��
bool IsEmptyQL1(QueueL1 Q);		//�ж϶����Ƿ�Ϊ��
ElementType1 DeleteQL1(QueueL1 Q);	//����ͷԪ�شӶ�����ɾ��������
//�������
void CengTraversal(BinTree bt);
