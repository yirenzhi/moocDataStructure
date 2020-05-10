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
Position Find1(ElementType X, BinTree BST);		//�ǵݹ��ʾ��
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

//�ݹ��ȥ�����㣬bstΪ��ʱ���ɽ�㲢����
BinTree Insert(ElementType X, BinTree BST);

//ɾ�����ڵ�ʱ�����ֻ��һ�����ӽ�㣺���丸�ڵ��ָ��ָ��Ҫɾ���ĺ��ӽ��
//��������������������һ��������ɾ����㣺����������СԪ�ػ��������������Ԫ�أ����ҵݹ��ɾ�������Ԫ��
BinTree Delete(ElementType X, BinTree BST);

