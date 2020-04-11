#include<vector>
#include<string>
#include<sstream>
#include <iostream>

using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode
{
	Tree left;
	Tree right;
}T3[MaxTree];
vector<Tree> vecNums;

#define ElementType1 int
struct  NodeL1
{
	ElementType1 Data;
	struct NodeL1* Next;
};

struct QNodeL1
{
	NodeL1 *rear;
	NodeL1 *front;
};

typedef QNodeL1 * QueueL1;
QueueL1 CreateQueueL1();	//生成长度为maxsize的空队列
void AddQL1(QueueL1 Q, ElementType1 item);	//将数据元素item插入队列Q中
bool IsEmptyQL1(QueueL1 Q);		//判断队列是否为空
ElementType1 DeleteQL1(QueueL1 Q);	//将对头元素从队列中删除并返回
QueueL1 CreateQueueL1()
{
	QueueL1 p = (QueueL1)malloc(sizeof(QNodeL1));
	p->front = NULL;
	p->rear = NULL;
	return p;
}
void AddQL1(QueueL1 Q, ElementType1 item)	//将数据元素item插入队列Q中
{
	NodeL1* s = (NodeL1*)malloc(sizeof(NodeL1));
	s->Data = item;
	if (IsEmptyQL1(Q))
	{
		Q->front = s;
		Q->rear = s;
	}
	else
	{
		NodeL1* p = Q->rear;
		p->Next = s;
		Q->rear = s;
	}
}
bool IsEmptyQL1(QueueL1 Q)		//判断队列是否为空
{
	return(Q->front == NULL);
}
ElementType1 DeleteQL1(QueueL1 Q)	//将对头元素从队列中删除并返回
{
	if (IsEmptyQL1(Q))
	{
		cout << "队列为空：" << endl;
		return 0;
	}
	NodeL1* p = Q->front;

	if (Q->front == Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = p->Next;
	}
	ElementType1 item = p->Data;
	free(p);
	return item;

}
Tree BuildTree1(TreeNode T[])
{
	Tree root = -1;
	int n;
	std::string str2;
	getline(cin, str2);
	stringstream ss1;
	ss1 << str2;

	ss1 >> n;
	int check[MaxTree];
	for (int i=0; i < n; i++)
	{
		check[i] = 0;
	}

	if (n != Null)
	{
		for (int i = 0; i < n; i++)
		{
			char left;
			char right;
			std::string str1;
			getline(cin, str1);
			stringstream ss;
			ss << str1;
			ss >> left >> right;

			if (left != '-')
			{
				T[i].left = left - '0';
				check[T[i].left] = 1;
			}
			else
			{
				T[i].left = Null;
			}

			if (right != '-')
			{
				T[i].right = right - '0';
				check[T[i].right] = 1;
			}
			else
			{
				T[i].right = Null;
			}

		}
		for (int i = 0; i < n; i++)
		{
			if (!check[i])
			{
				root = i;
				break;
			}
		}
	}
	return root;
}
//应该使用层序遍历，
void printTree(Tree r)
{
	Tree t = r;
	QueueL1 q = CreateQueueL1();
	AddQL1(q, r);
	while (!IsEmptyQL1(q))
	{
		t = DeleteQL1(q);
		if (T3[t].left == Null && T3[t].right == Null)
		{
			vecNums.push_back(t);
		}
		if (T3[t].left!=Null)
		{
			AddQL1(q, T3[t].left);
		}
		if (T3[t].right != Null)
		{
			AddQL1(q, T3[t].right);
		}

	}



}
int testExercise7()
{
	Tree r1;
	r1 = BuildTree1(T3);
	printTree(r1);
	for (int i=0;i<vecNums.size();i++)
	{
		cout << vecNums[i];
		if (i!=vecNums.size()-1)
		{
			cout << " ";
		}
	}
	cout << endl;
	//printTree(T1);
	
	return 0;
}