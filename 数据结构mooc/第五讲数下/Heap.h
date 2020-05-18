#pragma once
#include "../base.h"


typedef struct HNode *Heap; /* 堆的类型定义 */
struct HNode {
	int *Data; /* 存储元素的数组 */
	int Size;          /* 堆中当前元素个数 */
	int Capacity;      /* 堆的最大容量 */
};
typedef Heap MaxHeap; /* 最大堆 */
typedef Heap MinHeap; /* 最小堆 */

MaxHeap Create(int maxSize);
bool IsFull(MaxHeap H);
void Insert(MaxHeap H, int item);
bool IsEmpty(MaxHeap H);
int DeleteMax(MaxHeap H);
