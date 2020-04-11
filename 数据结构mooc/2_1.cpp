#include "2_1.h"
List MakeEmpty()
{
	int a = sizeof(struct LNode);
	int b = sizeof(LNode);
	List Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl->Last = -1;
	return Ptrl;
}

ElementType FindKth(int K, List L)
{
	if (K>L->Last)
	{
		return NULL;
	}
	return L->Data[K];
}

int Find(ElementType X, List L)
{
	for (int i = 0; i <= L->Last; i++)
	{
		if (X==L->Data[i])
		{
			return i;
		}
	}
	return -1;
}

void Insert(ElementType X, List L, int i)//;	//��Ϊ��iǰ����һ����Ԫ��X;
{
	if (L->Last + 1 >= MAXSIZE)
	{
		cout << "�б��������޷�����" << endl;
		return;
	}
	//�ж�λ���Ƿ�Ϸ�
	if (i<1 || i>L->Last + 2)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	for (int j = L->Last; j>=i-1; j--)
	{
		L->Data[j + 1] = L->Data[j];
	}
	L->Data[i-1] = X;
	L->Last++;
}

void Delete(int i, List L)	//	ɾ���ƶ�Ϊ��i��Ԫ�أ�
{
	if (i>L->Last+1 || i<1)
	{
		cout << "������ֵ�����б��ȣ�ɾ������";
		return;
	}
	for (int j = i-1; j < L->Last; j++)
	{
		L->Data[j] = L->Data[j + 1];
	}
	L->Last--;
}

int Length(List L)//;		//�������Ա���
{
	return L->Last + 1;
}

void printLNode(List L)//;	//������Ա�
{
	for (int i = 0; i <= L->Last; i++)
	{
		cout << L->Data[i] << "  ";
	}
	cout << endl;
}

void testLNode()
{
	List L = MakeEmpty();
	Insert(1, L, 1);
	Insert(2, L, 2);
	Insert(3, L, 3);
	Insert(4, L, 4);
	printLNode(L);

	Delete(2, L);
	printLNode(L);
	Insert(8, L, 3);
	printLNode(L);
}