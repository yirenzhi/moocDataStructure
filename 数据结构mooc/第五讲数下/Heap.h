#pragma once
#include "../base.h"


typedef struct HNode *Heap; /* 堆的类型定义 */
struct HNode {
	ElementType *Data; /* 存储元素的数组 */
	int Size;          /* 堆中当前元素个数 */
	int Capacity;      /* 堆的最大容量 */
};
typedef Heap MaxHeap; /* 最大堆 */
typedef Heap MinHeap; /* 最小堆 */

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
//最大堆得特性在于保持第一个元素最大，其他怎么排列无所谓，比如用有序数组当然可以做到同样的效果，但是插入的时间复杂度则要大得多
//用数组表示的完全二叉树，每个节点的元素值不小于其子结点的值
bool Insert(MaxHeap H, ElementType X)
{
	//0位置为哨兵，插入的第一个元素在1位置
	int i;
	if (IsFull(H))
	{
		cout << "最大堆已满" << endl;
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
	/*取出最大的元素，并删除一个节点*/
	int parent, child;
	ElementType maxItem, X;
	if (IsEmpty(H))
	{
		cout << "最大堆为空" << endl;
		return -1;
	}
	maxItem = H->Data[1];	//0存储的哨兵元素
	X = H->Data[H->Size--];
	//用最后一个元素从根节点开始从上向下过滤元素
	for ( parent = 1; parent*2 <= H->Size; parent=child)
	{
		child = parent * 2;
		if ((child!=H->Size)&&H->Data[child]<H->Data[child+1])
		{
			child++;	//child为孩子节点里大的那个
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


//建造最大堆
void PercDown(MaxHeap H, int p)
{
	int parent, child;
	ElementType  X;
	X = H->Data[p];
	//用最后一个元素从根节点开始从上向下过滤元素
	for (parent = p; parent * 2 <= H->Size; parent = child)
	{
		child = parent * 2;
		if ((child != H->Size) && H->Data[child]<H->Data[child + 1])
		{
			child++;	//child为孩子节点里大的那个
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
	//从最后一个节点的父节点开始，到根节点1
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