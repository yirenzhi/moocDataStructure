#pragma once
#include "../base.h"
class ShellSort
{
public:
	void test()
	{
		int a[10] = { 1,3,5,8,9,4,6,7,2,0 };
		Shell_Sort(a, 10);
		for (size_t i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

private:
	void Shell_Sort(int a[], int n)
	{
		for (int m = n/2; m>0 ; m/=2)
		{
			for (int i = m; i < n; i++)
			{
				int temp = a[i];
				int j = i;
				for (; j >=m && temp<a[j - m]; j-=m)
				{
					a[j] = a[j - m];
				}
				a[j] = temp;
			}
		}

	}

};

