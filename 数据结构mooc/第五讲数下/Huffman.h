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

	typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
	struct HNode {
		ElementType *Data; /* �洢Ԫ�ص����� */
		int Size;          /* ���е�ǰԪ�ظ��� */
		int Capacity;      /* �ѵ�������� */
	};
	typedef Heap MinHeap; /* ��С�� */

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
		//0λ��Ϊ�ڱ�������ĵ�һ��Ԫ����1λ��
		int i;
		if (IsFull(H))
		{
			cout << "��С������" << endl;
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
		/*ȡ������Ԫ�أ���ɾ��һ���ڵ�*/
		int parent, child;
		ElementType maxItem, X;
		if (IsEmpty(H))
		{
			cout << "����Ϊ��" << endl;
			return ;
		}
		maxItem = H->Data[1];	//0�洢���ڱ�Ԫ��
		X = H->Data[H->Size--];
		//�����һ��Ԫ�شӸ��ڵ㿪ʼ�������¹���Ԫ��
		for (parent = 1; parent * 2 <= H->Size; parent = child)
		{
			child = parent * 2;
			if ((child != H->Size) && H->Data[child]>H->Data[child + 1])
			{
				child++;	//childΪ���ӽڵ������Ǹ�
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
	//������С��
	void PercDown(MinHeap H, int p)
	{
		int parent, child;
		ElementType  X;
		X = H->Data[H->Size--];
		//�����һ��Ԫ�شӸ��ڵ㿪ʼ�������¹���Ԫ��
		for (parent = p; parent * 2 <= H->Size; parent = child)
		{
			child = parent * 2;
			if ((child != H->Size) && H->Data[child]>H->Data[child + 1])
			{
				child++;	//childΪ���ӽڵ������Ǹ�
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
		//�����һ���ڵ�ĸ��ڵ㿪ʼ�������ڵ�1
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