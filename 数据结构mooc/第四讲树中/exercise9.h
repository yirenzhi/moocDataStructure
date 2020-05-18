#pragma once
#include "../base.h"


/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No

解题思路，
*/
namespace EXERCISE9 {
	typedef struct TreeNode9 *Tree;

	struct TreeNode9
	{
		int v;
		Tree left, right;
		int flag;
		TreeNode9(int x) :v(x),left(NULL),right(NULL){}
	};

	class Exercise9
	{
	public:
		//收集数据
		void getDate() {

		}

		Tree Insert(Tree T, int V)
		{
			if (!T)
			{
				T = new TreeNode9(V);
			}
			else if (V<T->v)
			{
				T->left = Insert(T->left, V);
			}
			else if (V>T->v)
			{
				T->right = Insert(T->right, V);
			}
			return T;
		}

		Tree makeTree(int N)
		{
			Tree T;
			int i, V;
			cin >> V;
			T = new TreeNode9(V);
			for (size_t i = 1; i < N; i++)
			{
				cin >> V;
				Insert(T, V);
			}
			return T;
		}
		bool compareTree(Tree T, Tree T1)
		{
			if (T&&!T1)
			{
				return false;
			}
			else if (!T&&T1)
			{
				return false;
			}
			else if(!T&&!T1)
			{
				return true;

			}
			else if (T&&T1)
			{
				if (T->v != T1->v)
				{
					return false;
				}
				else
				{
					return compareTree(T->left, T1->left) && compareTree(T->right, T1->right);
				}
			}

		}
		void FreeTree(Tree T)
		{
			if (T)
			{
				FreeTree(T->left);
				FreeTree(T->right);
				free(T);
			}
		}

		void test() {
			Tree T,T1;
			int N, L;
			cin >> N;
			while (N)
			{
				cin >> L;
				T = makeTree(N);
				for (size_t i = 0; i < L; i++)
				{
					T1 = makeTree(N);
					if (compareTree(T,T1))
					{
						cout << "Yes" << endl;
					}
					else
					{
						cout << "No" << endl;
					}
					FreeTree(T1);
				}
				FreeTree(T);
				cin >> N;
			}

		}
	};


}
