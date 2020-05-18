#pragma once
#include "../base.h"


/*
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:
Yes
No
No

����˼·��
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
		//�ռ�����
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
