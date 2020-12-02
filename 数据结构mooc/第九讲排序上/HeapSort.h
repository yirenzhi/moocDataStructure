#pragma once
#include "../base.h"
class HeapSort
{
public:
	void test()
	{
		int a[10] = { 1,3,5,8,9,4,6,7,2,0 };
		//Selection_Sort(a, 10);
		Heap_Sort(a, 10);
		for (size_t i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
private:
	//ѡ������
	void Selection_Sort(int A[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			int pos = ScanForMin(A, i, n - 1);
			swap(A[i], A[pos]);
		}
	}

	int ScanForMin(int A[], int begin, int end)
	{
		int pos = begin;
		for (begin += 1; begin <= end; begin++)
		{
			if (A[begin] < A[pos])
			{
				pos = begin;
			}
		}
		return pos;
	}

	//void PercDown(int A[], int p, int N)
	//{
	//	//��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���������
	//	int Parent, Child;
	//	int X;

	//	X = A[p];//ȥ�����ڵ�
	//	for (Parent  = p; (Parent*2+1) < N; Parent=Child)
	//	{
	//		Child = Parent * 2 + 1;
	//		if ((Child!=N-1)&&(A[Child]<A[Child+1]))
	//		{
	//			Child++;
	//		}
	//		if (X>=A[Child])
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			A[Parent] = A[Child];
	//		}
	//	}
	//	A[Parent] = X;
	//}
	void PercDown(int A[], int p, int N)
	{
		int Parent, Child;
		int X = A[p];
		for (Parent = p; Parent < N / 2; Parent = Child)
		{
			Child = Parent * 2 + 1;
			if (Child != N - 1 && A[Child] < A[Child + 1])
			{
				++Child;
			}
			if (X > A[Child])
			{
				break;
			}
			else
			{
				A[Parent] = A[Child];
			}
		}
		A[Parent] = X;
	}

	//
	void Heap_Sort(int A[], int N)
	{
		//����
		//N���ܵĸ�����i���±꣬���Լ�1
		for (int i = N/2-1; i>=0 ; i--)
		{
			PercDown(A, i, N);
		}

		for (int i = N-1; i >0; i--)
		{
			swap(A[0], A[i]);
			PercDown(A, 0, i);
		}
	}



};

