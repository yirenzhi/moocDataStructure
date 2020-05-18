#pragma once
#include "../base.h"


typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
	int *Data; /* �洢Ԫ�ص����� */
	int Size;          /* ���е�ǰԪ�ظ��� */
	int Capacity;      /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */

MaxHeap Create(int maxSize);
bool IsFull(MaxHeap H);
void Insert(MaxHeap H, int item);
bool IsEmpty(MaxHeap H);
int DeleteMax(MaxHeap H);
