#pragma once
#include"../base.h"
#include<sstream>

class Solution24 : public Solution
{
public:
	virtual void test()
	{
		task();
	}

private:

	int task()
	{
		//¥¶¿Ì ‰»Î
		ifstream f("./TASK/task24.txt");
		int n;
		f >> n;
		vector<int> nums;
		for (size_t i = 0; i < n; i++)
		{
			int m;
			f >> m;
			nums.emplace_back(m);
		}
		paoSort(nums);
		//coutVector(nums);
		for (size_t i = 0; i < nums.size(); i++)
		{
			cout << nums[i];
			if (i!=nums.size()-1)
			{
				cout << " ";
			}
		}
		return 0;
	}
	int task1_()
	{
		int  n;
		cin >> n;
		vector<int> nums;

		for (size_t i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			nums.emplace_back(m);
		}
		insertSort(nums);
		return 0;
	}
	void insertSort(vector<int>& A)
	{
		size_t m = A.size();
		for (size_t i = 1; i < m; i++)
		{
			int j;
			int temp = A[i];
			for ( j = i ; j > 0 && A[j-1] > temp; j--)
			{
				A[j ] = A[j-1];
			}
			A[j] = temp;
		}

	}

	//√∞≈›≈≈–Ú
	void paoSort(vector<int>& A)
	{
		size_t m = A.size();
		for (size_t i = m-1; i > 0; i--)
		{
			bool flag = true;
			for (size_t j = 0;  j < i;  j++)
			{
				if (A[j] > A[j + 1])
				{
					swap(A[j], A[j + 1]);
					flag = false;
				}
			}
			if (flag)
			{
				break;

			}
		}
	}


};