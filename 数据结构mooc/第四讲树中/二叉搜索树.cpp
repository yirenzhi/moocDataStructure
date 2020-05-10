 #include "二叉搜索树.h"
 
 Position Find(ElementType X, BinTree BST)
 {
 	if (!BST)
 	{
 		return NULL;
 	}
 	if (X<BST->data)
 	{
 		return Find(X, BST->left);
 	}
 	else if (X>BST->data)
 	{
 		return Find(X, BST->right);
 	}
 	else
 	{
 		return BST;
 	}
 }
 
 Position Find1(ElementType X, BinTree BST)		//非递归表示法
 {
 	BinTree temp = BST;
 	while (temp)
 	{
 		if (X<temp->data)
 		{
 			temp = temp->left;
 		}
 		else if (X>temp->data)
 		{
 			temp = temp->right;
 		}
 		else
 		{
 			return temp;
 		}
 	}
 	return NULL;
 }
 Position FindMin(BinTree BST)
 {
 	BinTree temp = BST;
 	while (temp->left)
 	{
 		temp = temp->left;
 	}
 	return temp;
 }
 Position FindMax(BinTree BST)
 {
 	BinTree temp = BST;
 	if (!temp)
 	{
 		return NULL;
 	}
 	else if(!temp->left)
 	{
 		return temp;
 	}
 	else
 	{
 		return FindMax(temp->left);
 	}
 }

 BinTree Insert(ElementType X, BinTree BST)
 {
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TreeNode4));
		BST->data = X;
		BST->left = BST->right = NULL;
	}
	if (X<BST->data)
	{
		BST->left= Insert(X, BST->left);
	}
	else if (X>BST->data)
	{
		BST->right = Insert(X, BST->right);
	}

	return BST;
 }
 BinTree Delete(ElementType X, BinTree BST)
 {
	 Position temp;
	 if (!BST)
	 {
		 cout << "元素未找到。" << endl;
	 }
	 if (X<BST->data)
	 {
		 BST->left = Delete(X, BST->left);
	 }
	 else if (X>BST->data)
	 {
		 BST->right = Delete(X, BST->right);
	 }
	 else
	 {
		 //找到元素，通过他的子结点不同，进行不同的操作
		 if (BST->left&&BST->right)
		 {
			 //重点，此处替换右子树的最小元素
			 temp = FindMin(BST->right);
			 BST->data = temp->data;
			 //原本的又子树删除其最小元素
			 BST->right = Delete(temp->data, BST->right);
		 }
		 else
		 {
			 temp = BST;
			 if (!BST->left)	//	只有右节点或者没有结点，注意这里判断条件是非，而不是判断bst.right
			 {
				 BST = BST->right;
			 }
			 else {
				 BST = BST->left;
			 }
			 free(temp);

		 }

	 }

	 return BST;
 }
