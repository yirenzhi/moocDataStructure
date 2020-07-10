#pragma once
#include "../base.h"

//"ͼ�����ӱ��ʾ��"

namespace GRAPH2
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

	//�ڽӵ�Ķ���
	typedef struct AdjVNode *PtrToAdjVNode;
	struct AdjVNode
	{
		Vertex AdjV;
		WeightType Weight;
		PtrToAdjVNode Next;
	};

	//�����ͷ�ڵ�Ķ���
	typedef struct VNode {
		PtrToAdjVNode FirstEdge;	//�߱�ͷָ��
		DataType Data;	//�涥������ݷǱ���
	}AdjList[MaxVertexNum];

	//ͼ�ڵ�Ķ���
	typedef struct GNode *PtrToGNode;
	struct GNode
	{
		int Nv;
		int Ne;
		AdjList G;
	};

	typedef PtrToGNode LGraph;

	//ͼ���ڽӱ��ʾ��
	class GraphL
	{
	public:
		LGraph CreateGraph(int VertexNum);
		void InsertEdge(LGraph Graph, Edge E);
		LGraph BuildGraph();
		void Visit(Vertex V);
		void DFS(LGraph graph, Vertex V, void(GraphL::*Visit)(Vertex));
		void BFS(LGraph graph, Vertex S, void(GraphL::*Visit)(Vertex));

	private:
		vector<bool> Visited;

	};

	LGraph GraphL::CreateGraph(int VertexNum)
	{
		LGraph graph = (LGraph)malloc(sizeof(struct GNode));
		graph->Nv = VertexNum;
		graph->Ne = 0;
		for (int i = 0; i < VertexNum; i++)
		{
			graph->G[i].FirstEdge = NULL;
		}
		return graph;
	}
	void GraphL::InsertEdge(LGraph Graph, Edge E)
	{
		PtrToAdjVNode newNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		newNode1->AdjV = E->V1;
		newNode1->Weight = E->Weight;
		newNode1->Next = Graph->G[E->V2].FirstEdge->Next;
		Graph->G[E->V2].FirstEdge = newNode1;

		PtrToAdjVNode newNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		newNode2->AdjV = E->V2;
		newNode2->Weight = E->Weight;
		newNode2->Next = Graph->G[E->V1].FirstEdge->Next;
		Graph->G[E->V1].FirstEdge = newNode2;

	}
	LGraph GraphL::BuildGraph()
	{
		int Nv;
		cout << "���붥�����" << endl;
		cin >> Nv;

		LGraph graph = CreateGraph(Nv);
		cout << "���������" << endl;
		cin >> graph->Nv;
		if (graph->Nv>0)
		{
			Edge E = (Edge)malloc(sizeof(struct ENode));
			cout << "������� �յ� Ȩ�صĸ�ʽ���롣";
			for (int i = 0; i < graph->Nv; i++)
			{
				cin >> E->V1 >> E->V2 >> E->Weight;
				InsertEdge(graph, E);
			}
		}
		return graph;
	}

	void GraphL::Visit(Vertex V)
	{
		cout << "���ڷ��ʶ���" << V << endl;
		Visited[V] = true;

	}

	void GraphL::DFS(LGraph graph, Vertex V, void(GraphL::* Visit)(Vertex))
	{
		this->Visit(V);

		for (PtrToAdjVNode w = graph->G[V].FirstEdge; w; w=w->Next)
		{
			if (!Visited[w->AdjV])
			{
				DFS(graph, w->AdjV, Visit);
			}

		}
	}

	void GraphL::BFS(LGraph graph, Vertex S, void(GraphL::* Visit)(Vertex))
	{
		this->Visit(S);

		queue<Vertex> verQue;
		verQue.push(S);

		while (!verQue.empty())
		{
			Vertex V1 = verQue.front();
			verQue.pop();

			for (PtrToAdjVNode w = graph->G[V1].FirstEdge; w; w = w->Next)
			{
				this->Visit(w->AdjV);
				verQue.push(w->AdjV);
			}
		}
	}



}