#pragma once
#include "../base.h"

namespace HUFFMAN
{

	typedef struct HTreeNode *HuffmanTree;
	struct HTreeNode
	{
		int Weight;
		HuffmanTree Left, Right;
		bool operator>(const HTreeNode treeNode)
		{
			return this->Weight > treeNode.Weight;
		}
		bool operator<=(const HTreeNode treeNode)
		{
			return this->Weight <= treeNode.Weight;
		}
	};
	typedef HTreeNode ElementType;

	typedef struct HNode *Heap; /* 堆的类型定义 */
	struct HNode {
		ElementType *Data; /* 存储元素的数组 */
		int Size;          /* 堆中当前元素个数 */
		int Capacity;      /* 堆的最大容量 */
	};
	typedef Heap MinHeap; /* 最小堆 */

	#define MINDATA -1000
	MinHeap Create(int maxSize)
	{
		MinHeap H = (MinHeap )malloc(sizeof(struct HNode));
		H->Data = (ElementType*)malloc(sizeof(ElementType)*(maxSize + 1));
		H->Size = 0;
		H->Capacity = maxSize;
		H->Data[0].Weight = MINDATA;
		return H;
	}
	bool IsFull(MinHeap H)
	{
		return H->Size == H->Capacity;
	}

	bool Insert(MinHeap H, ElementType X)
	{
		//0位置为哨兵，插入的第一个元素在1位置
		int i;
		if (IsFull(H))
		{
			cout << "最小堆已满" << endl;
			return false;
		}
		i = ++H->Size;
		for (; H->Data[i / 2] > X; i /= 2)
		{
			H->Data[i] = H->Data[i / 2];
		}
		H->Data[i] = X;
		return true;
	}

	bool IsEmpty(MinHeap H)
	{
		return H->Size == 0;
	}
	ElementType* DeleteMin(MinHeap H)
	{
		/*取出最大的元素，并删除一个节点*/
		int parent, child;
		ElementType maxItem, X;
		if (IsEmpty(H))
		{
			cout << "最大堆为空" << endl;
			return ;
		}
		maxItem = H->Data[1];	//0存储的哨兵元素
		X = H->Data[H->Size--];
		//用最后一个元素从根节点开始从上向下过滤元素
		for (parent = 1; parent * 2 <= H->Size; parent = child)
		{
			child = parent * 2;
			if ((child != H->Size) && H->Data[child]>H->Data[child + 1])
			{
				child++;	//child为孩子节点里大的那个
			}
			if (X <= H->Data[child])
			{
				break;
			}
			else
			{
				H->Data[parent] = H->Data[child];
			}
		}
		H->Data[parent] = X;
		return &maxItem;
	}
	//建造最小堆
	void PercDown(MinHeap H, int p)
	{
		int parent, child;
		ElementType  X;
		X = H->Data[H->Size--];
		//用最后一个元素从根节点开始从上向下过滤元素
		for (parent = p; parent * 2 <= H->Size; parent = child)
		{
			child = parent * 2;
			if ((child != H->Size) && H->Data[child]>H->Data[child + 1])
			{
				child++;	//child为孩子节点里大的那个
			}
			if (X <= H->Data[child])
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

	void BuildMinHeap(MinHeap H)
	{
		int i;
		//从最后一个节点的父节点开始，到根节点1
		for (int i = H->Size / 2; i >0; i--)
		{
			PercDown(H, i);
		}
	}
	HuffmanTree Huffman(MinHeap H)
	{
		int i; HuffmanTree T;
		BuildMinHeap(H);
		for (size_t i = 0; i < H->Size; i++)
		{
			T = (HuffmanTree)malloc(sizeof(struct TreeNode));
			T->Left = DeleteMin(H);
		}
	}

}