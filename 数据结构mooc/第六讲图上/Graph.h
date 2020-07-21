#pragma once
#include "../base.h"
/* 图的邻接矩阵表示法 */

namespace GRAPH1
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

//图节点的定义
typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;	//	顶点数
	int Ne;	//	边数
	WeightType G[MaxVertexNum][MaxVertexNum];	//邻接矩阵
	DataType Data[MaxVertexNum];				//存顶点的数据
	//如果没有顶点数据则无需出现
};

typedef PtrToGNode MGraph;		//	以邻接矩阵存储的图类型

//图的矩阵表示法
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
	void init(int num);	//测试之前的初始化，主要用来将Visited全赋值为false
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
	//插入边
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph GraphJ::BuildGraph()
{
	int Nv;
	cout << "输入顶点个数" << endl;
	cin >> Nv;
	MGraph Graph = CreateGraph(Nv);

	cout << "请输入边数" << endl;
	cin >> Graph->Ne;
	if (Graph->Ne !=0)
	{
		Edge E = (Edge)malloc(sizeof(struct ENode));
		cout << "按照起点 终点 权重的格式输入。" << endl;
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
			cout << "插入完毕。" << endl;

		}

	}

	return Graph;
}
void GraphJ::Visit(Vertex V)
{
	cout << "正在访问顶点" << V << endl;
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
	cout << "深度优先搜索：" << endl;
	DFS(graph, 1, &GraphJ::Visit);

	cout << "广度优先搜索：" << endl;
	init(graph->Nv);
	BFS(graph, 1, &GraphJ::Visit);


}

void GraphJ::init(int num)
{
	Visited = vector<bool>(MaxVertexNum, false);

}

}
