#pragma once
#include "../base.h"
/* ͼ���ڽӾ����ʾ�� */

namespace GRAPH1
{

#define MaxVertexNum 100	//	��󶥵���
#define INFINITY 65535		//	�޷������������ֵ
typedef int Vertex;			//�����±��ʾ����
typedef int WeightType;		//�ߵ�Ȩֵ��Ϊ����
typedef char DataType;		//����洢������������Ϊ�ַ���

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex V1, V2;	//�����
	WeightType Weight;	//Ȩ��
};

typedef PtrToENode Edge;

//ͼ�ڵ�Ķ���
typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;	//	������
	int Ne;	//	����
	WeightType G[MaxVertexNum][MaxVertexNum];	//�ڽӾ���
	DataType Data[MaxVertexNum];				//�涥�������
	//���û�ж����������������
};

typedef PtrToGNode MGraph;		//	���ڽӾ���洢��ͼ����

//ͼ�ľ����ʾ��
class GraphJ
{
public:
	MGraph CreateGraph(int VertexNum);
	void InsertEdge(MGraph Graph, Edge E);
	MGraph BuildGraph();
	void Visit(Vertex V);
	void DFS(MGraph graph, Vertex V, void(GraphJ::*Visit)(Vertex));
	void BFS(MGraph Graph, Vertex S, void(GraphJ::*Visit)(Vertex));
	void test();
	void init(int num);	//����֮ǰ�ĳ�ʼ������Ҫ������Visitedȫ��ֵΪfalse
private:
	vector<bool> Visited;
};


MGraph GraphJ::CreateGraph(int VertexNum)
{
	MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (int i = 0; i < VertexNum; i++)
	{
		for (int j = 0; j < VertexNum; j++)
		{
			Graph->G[i][j] = INFINITY;
		}
	}
	return Graph;
}

void GraphJ::InsertEdge(MGraph Graph, Edge E)
{
	//�����
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph GraphJ::BuildGraph()
{
	int Nv;
	cout << "���붥�����" << endl;
	cin >> Nv;
	MGraph Graph = CreateGraph(Nv);

	cout << "���������" << endl;
	cin >> Graph->Ne;
	if (Graph->Ne !=0)
	{
		Edge E = (Edge)malloc(sizeof(struct ENode));
		cout << "������� �յ� Ȩ�صĸ�ʽ���롣" << endl;
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
			cout << "������ϡ�" << endl;

		}

	}

	return Graph;
}
void GraphJ::Visit(Vertex V)
{
	cout << "���ڷ��ʶ���" << V << endl;
	Visited[V] = true;

}
void GraphJ::DFS(MGraph graph, Vertex V, void(GraphJ::*Visit)(Vertex))
{
	this->Visit(V);

	for (int i = 0; i < graph->Nv; i++)
	{
		Vertex V1 = graph->G[V][i];
		if (V1 != INFINITY && !Visited[i])
		{
			DFS(graph, i, Visit);
		}

	}
}

void GraphJ::BFS(MGraph Graph, Vertex S, void(GraphJ::* Visit)(Vertex))
{
	this->Visit(S);

	queue<Vertex> verQue;
	verQue.push(S);

	while (!verQue.empty())
	{
		Vertex w = verQue.front();
		verQue.pop();
		for (int i = 0; i < Graph->Nv; i++)
		{
			Vertex V1 = Graph->G[w][i];
			if (V1 != INFINITY && !Visited[i])
			{
				//BFS(Graph, i, Visit);
				this->Visit(i);
				verQue.push(i);
			}
		}
	}
}

void GraphJ::test()
{
	MGraph graph = BuildGraph();
	init(graph->Nv);
//	void (GraphJ::*p)(Vertex) = Visit;
	cout << "�������������" << endl;
	DFS(graph, 1, &GraphJ::Visit);

	cout << "�������������" << endl;
	init(graph->Nv);
	BFS(graph, 1, &GraphJ::Visit);


}

void GraphJ::init(int num)
{
	Visited = vector<bool>(MaxVertexNum, false);

}

}
