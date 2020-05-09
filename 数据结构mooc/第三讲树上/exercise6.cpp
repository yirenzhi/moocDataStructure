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
	ElementType data;
	Tree left;
	Tree right;
}T1[MaxTree],T2[MaxTree];
int TreeNum = 0;
Tree BuildTree(TreeNode T[])
{
	Tree root=-1;
	int n;
	std::string str2;
	getline(cin, str2);
	stringstream ss1;
	ss1 << str2;

	ss1 >> n;
	TreeNum = n;
	int check[MaxTree];
	for (int i=0;i<n;i++)
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
			ss >> T[i].data >> left >> right;

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
void printTree(TreeNode T[])
{
	for (int i=0;i<8;i++)
	{
		cout << T[i].data << T[i].left << T[i].right << endl;
	}
}
bool Isomorphic(Tree R1, Tree R2)
{
	if ((R1==Null)&&(R2==Null))
	{
		return true;
	}
	if (((R1==Null)&&(R2!=Null))||((R1!=Null&&R2==Null)))
	{
		return false;
	}
	if (T1[R1].data!=T2[R2].data)
	{
		return false;
	}
	if ((T1[R1].left==Null)&&(T2[R2].left==Null))
	{
		return Isomorphic(T1[R1].right, T2[R2].right);
	}
	if ((T1[R1].left != Null) && (T2[R2].left != Null)&& (T1[T1[R1].left].data== T2[T2[R2].left].data))
	{
		return(Isomorphic(T1[R1].left, T2[R2].left), Isomorphic(T1[R1].right, T2[R2].right));
	}
	else
	{
		return(Isomorphic(T1[R1].left, T2[R2].right), Isomorphic(T1[R1].right, T2[R2].left));
	}
}
int testExercise6()
{
	Tree r1, r2;
	r1 = BuildTree(T1);
	int t1Nums = TreeNum;
	r2 = BuildTree(T2);
	int t2Nums = TreeNum;

	//printTree(T1);
	bool isOm = false;
	if (t1Nums!=t2Nums)
	{
		isOm = false;
	}
	else
	{
		isOm = Isomorphic(r1, r2);
	}
	if (isOm)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}