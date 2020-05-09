#pragma once
#include "../base.h"

LinkList LinkMakeEmpty();	//初始化一个空线性表
LinkList LinkFindKth(int K, LinkList L);	//通过位序找到相应元素
LinkList LinkFind(ElementType X, LinkList L);	//在线性表L中查找X的第一次出现位置
LinkList LinkInsert(ElementType X, LinkList L, int i);	//在为序i前插入一个新元素X;
LinkList LinkDelete(int i, LinkList L);	//	删除制定为序i的元素；
int LinkLength(LinkList L);		//返回线性表长度
void LinkprintLNode(LinkList L);	//输出线性表
void LinktestLNode();