#pragma once
#include <iostream>
using namespace std;
typedef struct PolyNode* Polynomial; //多项式的
struct PolyNode {
	int coef; //系数
	int expon;	//指数
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

List MakeEmpty();	//初始化一个空线性表
ElementType FindKth(int K, List L);	//通过位序找到相应元素
int Find(ElementType X, List L);	//在线性表L中查找X的第一次出现位置
void Insert(ElementType X, List L, int i);	//在为序i前插入一个新元素X;
void Delete(int i, List L);	//	删除制定为序i的元素；
int Length(List L);		//返回线性表长度
void printLNode(List L);	//输出线性表
void testLNode();