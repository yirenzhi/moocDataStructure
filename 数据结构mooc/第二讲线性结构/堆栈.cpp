#include"堆栈.h"


Stack createEmptyStack()
{
	Stack s = (Stack)malloc(sizeof(SNode));
	s->Top = -1;
	return s;
}
void PushStack(Stack PtrS, ElementType item)
{
	if (isFullStack(PtrS))
	{
		cout << "堆栈已满" << endl;
		return;
	}
	PtrS->Data[++PtrS->Top] = item;
}
ElementType PopStack(Stack PtrS)
{
	if (isEmptyStack(PtrS))
	{
		cout << "堆栈是空的" << endl;
		return -1;
	}
	return PtrS->Data[PtrS->Top--];
}
bool isEmptyStack(Stack PtrS)
{
	if (PtrS->Top==-1)
	{
		return true;
	}
	return false;
}
bool isFullStack(Stack PtrS)
{
	if (PtrS->Top==MaxSize-1)
	{
		return true;
	}
	return false;
}

void printStack(Stack PtrS)
{
	cout << "输出堆栈：" ;
	for (int i = 0; i <= PtrS->Top; i++)
	{
		cout << PtrS->Data[i] << " ";
	}
	cout << endl;
}

void testStack()
{
	Stack s = createEmptyStack();
	PushStack(s, 1);
	PushStack(s, 2);
	printStack(s);
	PopStack(s);
	printStack(s);
}

StackL createEmptyStackL()
{
	StackL s = (StackL)malloc(sizeof(SNodeL));
	s->Next = NULL;
	return s;
}
void PushStackL(StackL PtrS, ElementType item)
{
	cout << "插入元素：" << item << endl;
	StackL s = (StackL)malloc(sizeof(SNodeL));
	s->Data = item;
	s->Next = PtrS->Next;
	PtrS->Next = s;

}
ElementType PopStackL(StackL PtrS)
{
	if (isEmptyStackL(PtrS))
	{
		cout << "列表为空，无法弹出" << endl;
		return -1;
	}
	StackL p = PtrS->Next;
	PtrS->Next = p->Next;
	ElementType item = p->Data;
	free(p);
	cout << "弹出元素 " << item << endl;
	return item;
}
bool isEmptyStackL(StackL PtrS)
{
	return (PtrS->Next == NULL);
}
void printStackL(StackL PtrS)
{
	StackL p = PtrS->Next;
	cout << "输出堆栈：";
	while (p)
	{
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}
void testStackL()
{
	cout << "链式存储:" << endl;
	StackL s = createEmptyStackL();
	PushStackL(s, 1);
	PushStackL(s, 2);
	printStackL(s);
	PopStackL(s);
	printStackL(s);
}