 #include "����������.h"
 
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
 
 Position Find1(ElementType X, BinTree BST)		//�ǵݹ��ʾ��
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
		 cout << "Ԫ��δ�ҵ���" << endl;
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
		 //�ҵ�Ԫ�أ�ͨ�������ӽ�㲻ͬ�����в�ͬ�Ĳ���
		 if (BST->left&&BST->right)
		 {
			 //�ص㣬�˴��滻����������СԪ��
			 temp = FindMin(BST->right);
			 BST->data = temp->data;
			 //ԭ����������ɾ������СԪ��
			 BST->right = Delete(temp->data, BST->right);
		 }
		 else
		 {
			 temp = BST;
			 if (!BST->left)	//	ֻ���ҽڵ����û�н�㣬ע�������ж������Ƿǣ��������ж�bst.right
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
