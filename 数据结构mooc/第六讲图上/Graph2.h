#pragma once
#include "../base.h"

//"图的连接表表示法"

namespace GRAPH2
{

#define MaxVertexNum 100	//	最大顶点数
#define INFINITY 65535		//	无符号整数的最大值
	typedef int Vertex;			//顶点下标表示顶点
	typedef int WeightType;		//边的权值设为整形
	typedef char DataType;		//顶点存储的数据类型设为字符型

								//边的定义
	typedef struct ENode *PtrToENode;
	struct ENode
	{
		Vertex V1, V2;	//有向边
		WeightType Weight;	//权重
	};

	typedef PtrToENode Edge;

	//邻接点的定义
	typedef struct AdjVNode *PtrToAdjVNode;
	struct AdjVNode
	{
		Vertex AdjV;
		WeightType Weight;
		PtrToAdjVNode Next;
	};

	//顶点表头节点的定义
	typedef struct VNode {
		PtrToAdjVNode FirstEdge;	//边表头指针
		DataType Data;	//存顶点的数据非必须
	}AdjList[MaxVertexNum];

	//图节点的定义
	typedef struct GNode *PtrToGNode;
	struct GNode
	{
		int Nv;
		int Ne;
		AdjList G;
	};

	typedef PtrToGNode LGraph;

	//图的邻接表表示法
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
		cout << "输入顶点个数" << endl;
		cin >> Nv;

		LGraph graph = CreateGraph(Nv);
		cout << "请输入边数" << endl;
		cin >> graph->Nv;
		if (graph->Nv>0)
		{
			Edge E = (Edge)malloc(sizeof(struct ENode));
			cout << "按照起点 终点 权重的格式输入。";
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
		cout << "正在访问顶点" << V << endl;
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