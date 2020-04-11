#include "���Ĵ洢.h"


Stack1 createEmptyStack1()
{
	Stack1 s = (Stack1)malloc(sizeof(SNode1));
	s->Top = -1;
	return s;
}
void PushStack1(Stack1 PtrS, ElementType1 item)
{
	if (isFullStack1(PtrS))
	{
		cout << "��ջ����" << endl;
		return;
	}
	PtrS->Data[++PtrS->Top] = item;
}
ElementType1 PopStack1(Stack1 PtrS)
{
	if (isEmptyStack1(PtrS))
	{
		cout << "��ջ�ǿյ�" << endl;
		return NULL;
	}
	return PtrS->Data[PtrS->Top--];
}
bool isEmptyStack1(Stack1 PtrS)
{
	if (PtrS->Top == -1)
	{
		return true;
	}
	return false;
}
bool isFullStack1(Stack1 PtrS)
{
	if (PtrS->Top == MaxSize - 1)
	{
		return true;
	}
	return false;
}
void PreOrderTraversal(BinTree BT)
{
	if (BT)
	{
		cout << BT->Data;
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
	}
}
void InOrderTraversal(BinTree BT)
{
	if (BT)
	{
		PreOrderTraversal(BT->left);
		cout << BT->Data;
		PreOrderTraversal(BT->right);
	}
}
void PostOrderTraversal(BinTree BT)
{
	if (BT)
	{
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
		cout << BT->Data;
	}
}

void InOrderBianli(BinTree bt)
{
	BinTree t = bt;
	Stack1 s = createEmptyStack1();
	while (t || isEmptyStack1(s))
	{
		while (t)
		{
			PushStack1(s, t);
			t = t->left;
		}
		if (isEmptyStack1(s))
		{
			t = PopStack1(s);
			cout << t->Data;
			t = t->right;
		}

	}
}
//
int jundgeTree(BinTree bt)
{
	if (bt)
	{
		int lefth = jundgeTree(bt->left);
		int righth = jundgeTree(bt->right);
		int maxh = lefth>righth?lefth:righth;
		return maxh + 1;
	}
	else
	{
		return 0;
	}
}


void testTraveral()
{
	BinTree bt = (BinTree)malloc(sizeof(TreeNode));
	bt->Data = 1;

	BinTree bt2 = (BinTree)malloc(sizeof(TreeNode));
	bt2->Data = 2;
	bt2->left = NULL;
	bt2->right = NULL;
	BinTree bt3 = (BinTree)malloc(sizeof(TreeNode));
	bt3->Data = 3;
	bt3->left = NULL;
	bt3->right = NULL;

	bt->left = bt2;
	bt->right = bt3;

	PreOrderTraversal(bt);
	InOrderTraversal(bt);
	PostOrderTraversal(bt);
}

QueueL1 CreateQueueL1()
{
	QueueL1 p = (QueueL1)malloc(sizeof(QNodeL1));
	p->front = NULL;
	p->rear = NULL;
	return p;
}
void AddQL1(QueueL1 Q, ElementType1 item)	//������Ԫ��item�������Q��
{
	NodeL1* s = (NodeL1*)malloc(sizeof(NodeL1));
	s->Data = item;
	if (IsEmptyQL1(Q))
	{
		Q->front = s;
		Q->rear = s;
	}
	else
	{
		NodeL1* p = Q->rear;
		p->Next = s;
		Q->rear = s;
	}
}
bool IsEmptyQL1(QueueL1 Q)		//�ж϶����Ƿ�Ϊ��
{
	return(Q->front == NULL);
}
ElementType1 DeleteQL1(QueueL1 Q)	//����ͷԪ�شӶ�����ɾ��������
{
	if (IsEmptyQL1(Q))
	{
		cout << "����Ϊ�գ�" << endl;
		return NULL;
	}
	NodeL1* p = Q->front;

	if (Q->front == Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = p->Next;
	}
	ElementType1 item = p->Data;
	free(p);
	return item;

}

void CengTraversal(BinTree bt)
{
	BinTree t = bt;
	QueueL1 q = CreateQueueL1();
	AddQL1(q, t);
	while (IsEmptyQL1(q))
	{
		t = DeleteQL1(q);
		cout << t->Data;
		if (t->left)
		{
			AddQL1(q, t->left);
		}
		if (t->right)
		{
			AddQL1(q, t->right);
		}
	}
}
