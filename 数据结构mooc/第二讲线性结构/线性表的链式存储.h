#pragma once
#include "../base.h"

LinkList LinkMakeEmpty();	//��ʼ��һ�������Ա�
LinkList LinkFindKth(int K, LinkList L);	//ͨ��λ���ҵ���ӦԪ��
LinkList LinkFind(ElementType X, LinkList L);	//�����Ա�L�в���X�ĵ�һ�γ���λ��
LinkList LinkInsert(ElementType X, LinkList L, int i);	//��Ϊ��iǰ����һ����Ԫ��X;
LinkList LinkDelete(int i, LinkList L);	//	ɾ���ƶ�Ϊ��i��Ԫ�أ�
int LinkLength(LinkList L);		//�������Ա���
void LinkprintLNode(LinkList L);	//������Ա�
void LinktestLNode();