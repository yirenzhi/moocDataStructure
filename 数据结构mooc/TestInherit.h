#pragma once
#include "base.h"
class A
{
public:
	A()
	{
		cout << "A的构造函数" << endl;
	}
	void test1()
	{
		cout << "A test1" << endl;
		test2();
	}
	void test2()
	{
		cout << "A test2" << endl;
	}
private:

};


class B:public A
{
public:
	B()
	{
		cout << "B的构造函数" << endl;
	}
	//void test1()
	//{
	//	cout << "B test1" << endl;
	//}
	void test2()
	{
		cout << "B test2" << endl;
	}

private:

};



void testInherit()
{
	B* b = new B;
	b->test1();

}