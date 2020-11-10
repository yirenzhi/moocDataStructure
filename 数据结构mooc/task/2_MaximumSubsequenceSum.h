#pragma once
#include"../base.h"
#include<sstream>

class Solution2 : public Solution
{
public:
	virtual void test()
	{
		task2_();
	}
private:
	void task2()
	{
		//´¦ÀíÊäÈë
		ifstream f("./TASK/task2.txt");
		int n;
		f >> n;
		vector<int> nums;
		for (size_t i = 0; i < n; i++)
		{
			int m;
			f >> m;
			nums.emplace_back(m);
		}
		int x = 0, y = 0;

		cout << MaxSubseqSum(nums, x, y) << " " << x << " " << y;
	}

	int MaxSubseqSum(vector<int> nums, int& x, int& y)
	{
		int maxSum = -1;
		int thisSum = 0;
		int x_1 = nums[0];
		for (size_t i = 0; i < nums.size(); i++)
		{
			thisSum += nums[i];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
				y = nums[i];
				x = x_1;
			}
			else if (thisSum < 0)
			{
				thisSum = 0;
				if (i + 1 < nums.size())
				{
					x_1 = nums[i + 1];
				}
			}
		}
		if (maxSum<0)
		{
			maxSum = 0;
		}
		return maxSum;
	}

	int task2_()
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
		int x = nums[0], y = nums[nums.size()-1];
		cout<<MaxSubseqSum(nums,x,y)<<" "<<x<<" "<<y;
		return 0;
	}

	
};

