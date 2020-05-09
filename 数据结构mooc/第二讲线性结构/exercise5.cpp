
#include"堆栈.h"
#include<vector>
#include<string>
#include<sstream>
#include"堆栈.h"


bool IsWork(Stack s, int m, std::vector<int>  lines)
{
	int tag = 1; //用来标记
	int size = lines.size();
	if (isEmptyStack(s))
	{
		PushStack(s, tag);
		tag++;
	}
	for (int i=0;i<lines.size();i++)
	{

		while (s->Data[s->Top]!=lines[i])
		{
			PushStack(s, tag);
			
			if (tag>lines.size()||s->Top>m-1)
			{
				return false;
			}
			tag++;
		}
		int item = PopStack(s);
		if (isEmptyStack(s)&&tag<=lines.size())
		{
			PushStack(s, tag);
			tag++;
		}
		
	}
	return true;
}
void testExercise5()
{
	int m, n, k;
	std::string str2;
	getline(cin, str2);
	stringstream ss1;
	ss1 << str2;

	ss1 >> m >> n >> k;
	std::vector<std::vector<int>>  nums;
	for (int i = 0; i < k; i++)
	{
		std::vector<int> line;
		std::string str1;
		getline(cin, str1);
		stringstream ss;
		ss << str1;
		int item;
		while (ss>>item)
		{
			line.push_back(item);
		}
		nums.push_back(line);
	}
	//输出
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	//定义长度为m的堆栈
	
	for (int i=0;i<nums.size();i++)
	{
		Stack s = createEmptyStack();
		bool isCanwork = IsWork(s, m, nums[i]);
		if (isCanwork)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}





}