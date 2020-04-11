#pragma once
#include <iostream>
using namespace std;
typedef struct PolyNode* Polynomial; //����ʽ��
struct PolyNode {
	int coef; //ϵ��
	int expon;	//ָ��
	Polynomial link;
};
#define MAXSIZE 1024
typedef int ElementType;
//#define ElementType int;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};
//struct LNode L;
//List Ptrl;

List MakeEmpty();	//��ʼ��һ�������Ա�
ElementType FindKth(int K, List L);	//ͨ��λ���ҵ���ӦԪ��
int Find(ElementType X, List L);	//�����Ա�L�в���X�ĵ�һ�γ���λ��
void Insert(ElementType X, List L, int i);	//��Ϊ��iǰ����һ����Ԫ��X;
void Delete(int i, List L);	//	ɾ���ƶ�Ϊ��i��Ԫ�أ�
int Length(List L);		//�������Ա���
void printLNode(List L);	//������Ա�
void testLNode();