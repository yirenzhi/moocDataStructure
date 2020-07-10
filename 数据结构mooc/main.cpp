#include <iostream>
#include <map>
#include <string>
#include "�ڶ������Խṹ\2_1.h"
#include "�ڶ������Խṹ\��ջ.h"
#include <vector>
#include <stack>
#include "���Ľ�����\ƽ�������.h"
#include "���Ľ�����\exercise9.h"
#include "����������\���Ĵ洢.h"
#include "TestInherit.h"
#include "������ͼ��\Graph.h"
#include "������ͼ��\Graph2.h"
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
/*147. ˮ�ɻ���
����English
ˮ�ɻ����Ķ����ǣ������������ÿһλ���ϵ��ݴ�֮�� ��ά���ٿƵĶ���

����һ��3λ��ʮ��������153����һ��ˮ�ɻ�������Ϊ 153 = 13 + 53 + 33��

��һ��4λ��ʮ������1634Ҳ��һ��ˮ�ɻ�������Ϊ 1634 = 14 + 64 + 34 + 44��

����n���ҵ����е�nλʮ����ˮ�ɻ�����

����
���� 1:

����: 1
���: [0,1,2,3,4,5,6,7,8,9]
���� 2:

����:  2
���: []
��������: û��2λ����ˮ�ɻ�����
ע������
�������ΪnС��8��
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
20. ��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

���ж��Ƿ������ź�����ַ���������ѹ��ջ�У��ǵĻ�����ջ�����һ���ַ����бȽ���ͬ�򵯳�ջ�����һ��Ԫ�أ���ͬ�򷵻���Ч
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

	//���Ե��Ľ�
	//����������

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

