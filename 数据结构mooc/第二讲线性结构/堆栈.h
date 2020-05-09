#pragma once
#include <iostream>
using namespace std;
#define MaxSize 1024
typedef int ElementType ;
typedef struct SNode* Stack;
struct SNode {
	ElementType Data[MaxSize];
	int Top;
};

Stack createEmptyStack();
void PushStack(Stack PtrS, ElementType item);
ElementType PopStack(Stack PtrS);
bool isEmptyStack(Stack PtrS);
bool isFullStack(Stack PtrS);

void printStack(Stack PtrS);
void testStack();


//用一个数组实现两个堆栈
struct DStack
{
	ElementType Data[MaxSize];
	int top1;
	int top2;

};

//堆栈链式存储
typedef struct SNodeL * StackL;
struct SNodeL {
	ElementType Data;
	struct SNodeL* Next;
};


StackL createEmptyStackL();
void PushStackL(StackL PtrS, ElementType item);
ElementType PopStackL(StackL PtrS);
bool isEmptyStackL(StackL PtrS);
void printStackL(StackL PtrS);
void testStackL();