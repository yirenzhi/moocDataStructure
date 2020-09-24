#pragma once
#include"../base.h"
class SimpleSort
{
public:
	void test() {
		int a[10] = { 1,3,5,8,9,4,6,7,2,0 };
		Insertion_Sort2(a, 10);
		for (size_t i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
private:
	//增加flag，如果本来有序可以一次通过
	void Bubble_Sort(int A[], int n)
	{
		for (int p = n-1; p >0; p--)
		{
			int flag = 0;
			for (int i = 0; i < p; i++)
			{
				if (A[i] > A[i + 1])
				{
					swap(A[i], A[i + 1]);
					flag = 1;
				}
			}
			if (flag==0)
			{
				break;
			}
		}
	}

	void Insertion_Sort(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; j>0 ; j--)
			{
				if (a[j-1] > temp)
				{
					a[j] = a[j - 1];
				}
				else
				{
					break;
				}

			}
			a[j] = temp;
		}
	}


	void Insertion_Sort2(int a[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; j >0&& temp < a[j - 1]; j--)
			{
					a[j] = a[j - 1];
			}
			a[j] = temp;
		}
	}

};

