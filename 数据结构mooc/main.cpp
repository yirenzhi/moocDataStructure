#include <iostream>
#include <map>
#include <string>
#include "第二讲线性结构\2_1.h"
#include "第二讲线性结构\堆栈.h"
#include <vector>
#include <stack>
#include "第四讲树中\平衡二叉树.h"
#include "第四讲树中\exercise9.h"
#include "第三讲树上\树的存储.h"
#include "TestInherit.h"
#include "第六讲图上\Graph.h"
#include "第六讲图上\Graph2.h"
using namespace std;
void testExercise5();
int testExercise6();
int testExercise7();

void testMap()
{
	map<int, string> map1;
	
	//map1.insert(pair<int, string>(1, "a"));
	map1[1] = "a";
	map1.insert(pair<int, string>(2, "c"));
	cout << "size:" << map1.size() << endl;
	map<int, string>::iterator type1= map1.begin();
	while (type1!=map1.end())
	{
		cout << "key:" << type1->first << " value:"<<type1->second << endl;
		type1++;
	}
//	map1.insert(make_pair(1, "b"));
	map1[1] = "b";
	cout << "size:" << map1.size() << endl;
	type1 = map1.begin();
	while (type1 != map1.end())
	{
		cout << "key:" << type1->first << " value:" << type1->second << endl;
		type1++;
	}
}
/*147. 水仙花数
中文English
水仙花数的定义是，这个数等于他每一位数上的幂次之和 见维基百科的定义

比如一个3位的十进制整数153就是一个水仙花数。因为 153 = 13 + 53 + 33。

而一个4位的十进制数1634也是一个水仙花数，因为 1634 = 14 + 64 + 34 + 44。

给出n，找到所有的n位十进制水仙花数。

样例
样例 1:

输入: 1
输出: [0,1,2,3,4,5,6,7,8,9]
样例 2:

输入:  2
输出: []
样例解释: 没有2位数的水仙花数。
注意事项
你可以认为n小于8。
list1 = []
for i in range(pow(10, n - 1) - 1, pow(10, n)) :
	listNum = []
	for j in range(n) :*/
vector<int> getNarcissisticNumbers(int n) {
	// write your code here
	vector<int > nums;
	int i = pow(10, n - 1);
	if (1==n)
	{
		i -= 1;
	}

	for (;i<pow(10,n);i++)
	{
		vector<int> shuzi;
		for (int j = 0; j < n; j++)
		{
			shuzi.push_back(int(i / pow(10, j)) % 10);
		}
		int counta = 0;
		for (auto x : shuzi) {
			counta += pow(x,n);
		}
		if (counta == i)
		{
			nums.push_back(i);
		}
	}
	return nums;

}

/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

先判断是否是括号后面的字符，不是则压入栈中，是的话则与栈中最后一个字符进行比较相同则弹出栈中最后一个元素，不同则返回无效
*/
bool isValid(string s) {
	map<char, char> mapStr;
	mapStr.insert(pair<char, char>(')', '('));
	mapStr.insert(pair<char, char>('}', '{'));
	mapStr.insert(pair<char, char>(']', '['));
	stack<char> staStr;
	for (size_t i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (mapStr.find(c)!=mapStr.end())
		{
			char topElement = staStr.empty() ? 'c' : staStr.top();
			if (topElement != mapStr[s[i]])
			{
				return false;
			}
			staStr.pop();

		}
		else
		{
			staStr.push(c);
		}
	}
	return (staStr.empty());
}

typedef union 
{
	int a;
	int b;
	char c;
	double d;
	//string m;
}testUnion;
int main()
{
	cout << "start" << endl;
	//testMap();

	//vector<string> strs;
	//strs.push_back("()");
	//strs.push_back("()[]{}");
	//strs.push_back("(]");
	//strs.push_back("([)]");
	//strs.push_back("{[]}");
	//for (size_t i = 0; i < strs.size(); i++)
	//{
	//	printf("%d\n", isValid(strs[i]));
	//}





	//
	//testLNode();

	//testStack();
	//testStackL();
// 	testExercise5();

// 	testTraveral();
// 	testExercise6();
//	testExercise7();

	//while (true)
	//{
	//	int n;
	//	cin >> n;
	//	if (n==-1)
	//	{
	//		break;
	//	}
	//	vector<int> test1 = getNarcissisticNumbers(n);
	//	for (auto x : test1) {
	//		cout << x <<"  " ;
	//	}
	//	cout << endl;
	//}

	//测试第四讲
	//二叉搜索数

	//AVLNODE::AVLNodeTest().test();

	//EXERCISE9::Exercise9().test();

	//testInherit();

	GRAPH1::GraphJ().test();

	//testUnion tempUnion;
	//tempUnion.a = 1;


	int m;
	cin >> m;
	return 0;
}

