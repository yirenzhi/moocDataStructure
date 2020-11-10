#pragma once
#include"../base.h"
#include<sstream>

class Solution1 : public Solution
{
public:
	virtual void test()
	{
		task1_();
	}
private:
	void task1()
	{
		//´¦ÀíÊäÈë
		ifstream f("./TASK/task1.txt");
		int n;
		f >> n;
		vector<int> nums;
		for (size_t i = 0; i < n; i++)
		{
			int m;
			f >> m;
			nums.emplace_back(m);
		}
		MaxSubseqSum(nums);
	}
	void task1_()
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
		MaxSubseqSum(nums);

	}

	int MaxSubseqSum(vector<int> nums)
	{
		int maxSum = 0;
		int thisSum = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			thisSum += nums[i];
			if (thisSum>maxSum)
			{
				maxSum = thisSum;
			}
			else if (thisSum <0)
			{
				thisSum = 0;
			}
		}
		return maxSum;
	}
};

