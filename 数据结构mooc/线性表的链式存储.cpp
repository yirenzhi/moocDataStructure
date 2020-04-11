#include"线性表的链式存储.h"


LinkList LinkMakeEmpty()	//初始化一个空线性表
{
	LinkList p = (LinkList)malloc(sizeof(LinkNode));
	p->Next = NULL;
	return p;

}
LinkList LinkFindKth(int K, LinkList L)	//通过位序找到相应元素
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
LinkList LinkFind(ElementType X, LinkList L)	//在线性表L中查找X的第一次出现位置
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
LinkList LinkInsert(ElementType X, LinkList L, int i)	//在为序i前插入一个新元素X;
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
		cout << "i位置不合理" << endl;
	}

	return NULL;

}
LinkList LinkDelete(int i, LinkList L)	//	删除制定为序i的元素；
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
		cout << "i位置不合理" << endl;
	}
	return NULL;
}
int LinkLength(LinkList L)		//返回线性表长度
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
void LinkprintLNode(LinkList L);	//输出线性表
void LinktestLNode();