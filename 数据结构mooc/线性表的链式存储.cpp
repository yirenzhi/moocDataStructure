#include"���Ա����ʽ�洢.h"


LinkList LinkMakeEmpty()	//��ʼ��һ�������Ա�
{
	LinkList p = (LinkList)malloc(sizeof(LinkNode));
	p->Next = NULL;
	return p;

}
LinkList LinkFindKth(int K, LinkList L)	//ͨ��λ���ҵ���ӦԪ��
{
	LinkList p = L;
	int j = 1;
	while (p)
	{
		if (K==j)
		{
			return p;
		}
		p = p->Next;
		j++;
	}
	return NULL;
}
LinkList LinkFind(ElementType X, LinkList L)	//�����Ա�L�в���X�ĵ�һ�γ���λ��
{
	LinkList p = L;
	//while (p)
	//{
	//	if (X == p->Data)
	//	{
	//		return p;
	//	}
	//	p = p->Next;
	//}
	//return NULL;

	while (p!=NULL && X!=p->Data)
	{
		p = p->Next;
	}
	return p;
}
LinkList LinkInsert(ElementType X, LinkList L, int i)	//��Ϊ��iǰ����һ����Ԫ��X;
{
	LinkList p, s;
	if (i==1)
	{
		s = (LinkList)malloc(sizeof(LinkNode));
		s->Data = X;
		s->Next = L;
		return s;
	}
	p = LinkFindKth(i - 1, L);
	if (p)
	{
		s = (LinkList)malloc(sizeof(LinkNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return L;
	}
	else
	{
		cout << "iλ�ò�����" << endl;
	}

	return NULL;

}
LinkList LinkDelete(int i, LinkList L)	//	ɾ���ƶ�Ϊ��i��Ԫ�أ�
{
	LinkList p, s;
	if (1==i)
	{
		s = L;
		if (L)
		{
			L = L->Next;
			free(s);
			return L;
		}
		else
		{
			return NULL;
		}
	}
	p = LinkFindKth(i - 1, L);
	if (p && p->Next)
	{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return L;
	}
	else
	{
		cout << "iλ�ò�����" << endl;
	}
	return NULL;
}
int LinkLength(LinkList L)		//�������Ա���
{
	LinkList p = L;
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}
void LinkprintLNode(LinkList L);	//������Ա�
void LinktestLNode();