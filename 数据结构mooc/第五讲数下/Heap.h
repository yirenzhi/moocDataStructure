#pragma once
#include "../base.h"


typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	int Size;          /* ���е�ǰԪ�ظ��� */
	int Capacity;      /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */

#define MAXDATA 1000

MaxHeap Create(int maxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType)*(MAXDATA + 1));
	H->Size = 0;
	H->Capacity = maxSize;
	H->Data[0] = MAXDATA;
	return H;
}
bool IsFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}
//���ѵ��������ڱ��ֵ�һ��Ԫ�����������ô��������ν���������������鵱Ȼ��������ͬ����Ч�������ǲ����ʱ�临�Ӷ���Ҫ��ö�
//�������ʾ����ȫ��������ÿ���ڵ��Ԫ��ֵ��С�����ӽ���ֵ
bool Insert(MaxHeap H, ElementType X)
{
	//0λ��Ϊ�ڱ�������ĵ�һ��Ԫ����1λ��
	int i;
	if (IsFull(H))
	{
		cout << "��������" << endl;
		return false;
	}
	i = ++H->Size;
	for (; H->Data[i/2] < X; i/=2)
	{
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = X;
	return true;
}
bool IsEmpty(MaxHeap H)
{
	return H->Size == 0;
}
int DeleteMax(MaxHeap H)
{
	/*ȡ������Ԫ�أ���ɾ��һ���ڵ�*/
	int parent, child;
	ElementType maxItem, X;
	if (IsEmpty(H))
	{
		cout << "����Ϊ��" << endl;
		return -1;
	}
	maxItem = H->Data[1];	//0�洢���ڱ�Ԫ��
	X = H->Data[H->Size--];
	//�����һ��Ԫ�شӸ��ڵ㿪ʼ�������¹���Ԫ��
	for ( parent = 1; parent*2 <= H->Size; parent=child)
	{
		child = parent * 2;
		if ((child!=H->Size)&&H->Data[child]<H->Data[child+1])
		{
			child++;	//childΪ���ӽڵ������Ǹ�
		}
		if (X>=H->Data[child])
		{
			break;
		}
		else
		{
			H->Data[parent] = H->Data[child];
		}
	}
	H->Data[parent] = X;
	return maxItem;
}


//��������
void PercDown(MaxHeap H, int p)
{
	int parent, child;
	ElementType  X;
	X = H->Data[p];
	//�����һ��Ԫ�شӸ��ڵ㿪ʼ�������¹���Ԫ��
	for (parent = p; parent * 2 <= H->Size; parent = child)
	{
		child = parent * 2;
		if ((child != H->Size) && H->Data[child]<H->Data[child + 1])
		{
			child++;	//childΪ���ӽڵ������Ǹ�
		}
		if (X >= H->Data[child])
		{
			break;
		}
		else
		{
			H->Data[parent] = H->Data[child];
		}
	}
	H->Data[parent] = X;
}

void BuildHeap()
{
	int i;
	//�����һ���ڵ�ĸ��ڵ㿪ʼ�������ڵ�1
	MaxHeap H = Create(10);
	H->Data[1] = 2;
	H->Data[2] = 3;
	H->Data[3] = 4;
	H->Data[4] = 5;
	H->Size = 4;
	for (int i = H->Size / 2; i >0; i--)
	{
		PercDown(H, i);
	}
}