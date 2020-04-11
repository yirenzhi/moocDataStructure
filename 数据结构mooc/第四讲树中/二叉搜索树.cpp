// #include "二叉搜索树.h"
// 
// Position Find(ElementType X, BinTree BST)
// {
// 	if (!BST)
// 	{
// 		return NULL;
// 	}
// 	if (X<BST->data)
// 	{
// 		return Find(X, BST->left);
// 	}
// 	else if (X>BST->data)
// 	{
// 		return Find(X, BST->right);
// 	}
// 	else
// 	{
// 		return BST->data;
// 	}
// }
// 
// Position Find1(ElementType X, BinTree BST)		//非递归表示法
// {
// 	BinTree temp = BST;
// 	while (temp)
// 	{
// 		if (X<temp->data)
// 		{
// 			temp = temp->left;
// 		}
// 		else if (X>temp->data)
// 		{
// 			temp = temp->right;
// 		}
// 		else
// 		{
// 			return temp;
// 		}
// 	}
// 	return NULL;
// }
// Position FindMin(BinTree BST)
// {
// 	BinTree temp = BST;
// 	while (temp->left)
// 	{
// 		temp = temp->left;
// 	}
// 	return temp;
// }
// Position FindMax(BinTree BST)
// {
// 	BinTree temp = BST;
// 	if (!temp)
// 	{
// 		return NULL;
// 	}
// 	else if(!temp->left)
// 	{
// 		return temp;
// 	}
// 	else
// 	{
// 		return FindMax(temp->left);
// 	}
// }