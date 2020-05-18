#pragma once
#include "../base.h"
namespace AVLNODE {
#define ElementType int
	typedef struct AVLNode *Position;
	typedef Position AVLTree; /* AVL������ */
	struct AVLNode {
		ElementType Data; /* ������� */
		AVLTree Left;     /* ָ�������� */
		AVLTree Right;    /* ָ�������� */
		int Height;       /* ���� */
		AVLNode(ElementType data) :Data(data), Left(NULL), Right(NULL), Height(0) {}
	};
	class AVLNodeTest
	{
	public:
		int GetHeight(AVLTree tree) {
			if (!tree)
			{
				return 0;
			}
			return tree->Height;
		}


		int Max(int a, int b)
		{
			return a > b ? a : b;
		}
		AVLTree SingleLeftRotation(AVLTree A)
		{ /* ע�⣺A������һ�����ӽ��B */
		  /* ��A��B������������A��B�ĸ߶ȣ������µĸ����B */

			AVLTree B = A->Left;
			A->Left = B->Right;
			B->Right = A;
			A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
			B->Height = Max(GetHeight(B->Left), A->Height) + 1;

			return B;
		}

		AVLTree DoubleLeftRightRotation(AVLTree A)
		{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
		  /* ��A��B��C�����ε����������µĸ����C */

		  /* ��B��C���ҵ�����C������ */
			A->Left = SingleRightRotation(A->Left);
			/* ��A��C��������C������ */
			return SingleLeftRotation(A);
		}

		/*************************************/
		/* �ԳƵ��ҵ�������-��˫�����Լ�ʵ�� */
		/*************************************/
		AVLTree SingleRightRotation(AVLTree A)
		{
			AVLTree B = A->Right;
			A->Right = B->Left;
			B->Left = A;
			A->Height = Max(GetHeight(A->Right), GetHeight(A->Left)) + 1;
			B->Height = Max(GetHeight(B->Right), A->Height) + 1;

			return B;
		}
		AVLTree DoubleRightLeftRotation(AVLTree A)
		{
			A->Right = SingleLeftRotation(A->Right);
			return SingleRightRotation(A);
		}

		AVLTree Insert(AVLTree T, ElementType X)
		{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
			if (!T) { /* ��������������½�����һ�������� */
				T = (AVLTree)malloc(sizeof(struct AVLNode));
				T->Data = X;
				T->Height = 0;
				T->Left = T->Right = NULL;
			} /* if (�������) ���� */

			else if (X < T->Data) {
				/* ����T�������� */
				T->Left = Insert(T->Left, X);
				/* �����Ҫ���� */
				if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
					if (X < T->Left->Data)
						T = SingleLeftRotation(T);      /* ���� */
					else
						T = DoubleLeftRightRotation(T); /* ��-��˫�� */
			} /* else if (����������) ���� */

			else if (X > T->Data) {
				/* ����T�������� */
				T->Right = Insert(T->Right, X);
				/* �����Ҫ���� */
				if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
					if (X > T->Right->Data)
						T = SingleRightRotation(T);     /* �ҵ��� */
					else
						T = DoubleRightLeftRotation(T); /* ��-��˫�� */
			} /* else if (����������) ���� */

			  /* else X == T->Data��������� */

			  /* �����˸������� */
			T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;

			return T;
		}

		void printTree(AVLTree A)
		{
			if (A)
			{
				cout << A->Data << endl;
				printTree(A->Left);
				printTree(A->Right);
			}
			else
			{
				cout << "null" << endl;
			}
		}
		void test()
		{
			cout << "������һ��Ԫ��:" << endl;
			int m = 0;
			cin >> m;
			AVLTree A = new AVLNode(m);

			while (m != -1)
			{
				cout << "�����Ԫ��:" << endl;
				cin >> m;
				if (99 == m)
				{
					printTree(A);
				}
				else
				{
					A = Insert(A, m);
				}
			}

		}
	};
}

