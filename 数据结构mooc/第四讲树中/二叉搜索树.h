#pragma once
#include<vector>
#include<string>
#include<sstream>
#include <iostream>

using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
typedef TreeNode4* Position, *BinTree;
struct TreeNode4
{
	ElementType data;
	BinTree left;
	BinTree right;
};


Position Find(ElementType X, BinTree BST);
Position Find1(ElementType X, BinTree BST);		//非递归表示法
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
