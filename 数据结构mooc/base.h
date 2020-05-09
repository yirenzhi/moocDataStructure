#pragma once
#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

typedef int ElementType;
typedef struct LinkNode* LinkList;
struct LinkNode
{
	ElementType Data;
	LinkList Next;
};

#define MaxSize 1024
struct QNodeS {
	ElementType Data[MaxSize];
	int rear;
	int front;
};

struct  NodeL
{
	ElementType Data;
	struct NodeL* Next;
};

struct QNodeL
{
	NodeL *rear;
	NodeL *front;
};
