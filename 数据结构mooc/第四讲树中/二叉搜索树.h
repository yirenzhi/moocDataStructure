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
typedef struct TreeNode4* Position, *BinTree;

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

//递归的去插入结点，bst为空时生成结点并返回
BinTree Insert(ElementType X, BinTree BST);

//删除树节点时，如果只有一个孩子结点：将其父节点的指针指向要删除的孩子结点
//有左右两个子树，用另一结点替代被删除结点：右子树的最小元素或者左子树的最大元素，并且递归的删除替代的元素
BinTree Delete(ElementType X, BinTree BST);

