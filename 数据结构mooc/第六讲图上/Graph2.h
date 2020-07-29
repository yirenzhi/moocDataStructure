#pragma once
#include "../base.h"
#include <fstream>

#include <direct.h>
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
		int Nv;//	顶点数
		int Ne;//	边数
		AdjList G;
	};

	typedef PtrToGNode LGraph;

	//图的邻接表表示法
	class GraphL
	{
	public:
		LGraph CreateGraph(int VertexNum);
		void InsertEdge(LGraph Graph, Edge E,bool isD=true);
		LGraph BuildGraph();
		void Visit(Vertex V);
		void DFS(LGraph graph, Vertex V, void(GraphL::*Visit)(Vertex));
		void BFS(LGraph graph, Vertex S, void(GraphL::*Visit)(Vertex));
		void test();
		void init(int num);	//测试之前的初始化，主要用来将Visited全赋值为false

		/* 邻接表存储 - 无权图的单源最短路算法 */
		/* dist[]和path[]全部初始化为-1 */
		void Unweighted(LGraph Graph, int dist[], int path[], Vertex S);
		LGraph BuildGraphFromTxt();
		//有权图的单源最短路算法
		bool Dijkstra(LGraph Graph, int dist[], int path[], Vertex S);
		Vertex FindMinDist(LGraph Graph, int dist[], bool collected[]);

		//最小生成树问题，
		int Prim(LGraph graph, LGraph mst);
		Vertex FindMinDist(LGraph Graph, WeightType dist[]);

		//拓扑排序，T=O(|V|+|Es|)
		bool TopSort(LGraph Graph, Vertex TopOrder[]);
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
	void GraphL::InsertEdge(LGraph Graph, Edge E, bool isD)
	{
		if (isD)
		{
			PtrToAdjVNode newNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
			newNode1->AdjV = E->V1;
			newNode1->Weight = E->Weight;
			newNode1->Next = Graph->G[E->V2].FirstEdge;
			Graph->G[E->V2].FirstEdge = newNode1;
		}


		PtrToAdjVNode newNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		newNode2->AdjV = E->V2;
		newNode2->Weight = E->Weight;
		newNode2->Next = Graph->G[E->V1].FirstEdge;
		Graph->G[E->V1].FirstEdge = newNode2;


	}
	LGraph GraphL::BuildGraph()
	{
		int Nv;
		cout << "输入顶点个数" << endl;
		cin >> Nv;

		LGraph graph = CreateGraph(Nv);
		cout << "请输入边数" << endl;
		cin >> graph->Ne;
		if (graph->Ne>0)
		{
			Edge E = (Edge)malloc(sizeof(struct ENode));
			cout << "按照起点 终点 权重的格式输入。" << endl;;
			for (int i = 0; i < graph->Ne; i++)
			{
				cin >> E->V1 >> E->V2 >> E->Weight;
				InsertEdge(graph, E);
				cout << "插入完毕。" << endl;

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
				if (!Visited[w->AdjV])
				{
					this->Visit(w->AdjV);
					verQue.push(w->AdjV);
				}
			}
		}
	}
	//无权图的最短路径算法
	void GraphL::Unweighted(LGraph graph, int dist[], int path[], Vertex S)
	{
		queue<Vertex> verQue;
		verQue.push(S);

		dist[S] = 0;

		while (!verQue.empty())
		{
			Vertex V1 = verQue.front();
			verQue.pop();

			for (PtrToAdjVNode w = graph->G[V1].FirstEdge; w; w = w->Next)
			{
				if (dist[w->AdjV]== INFINITY)
				{
					dist[w->AdjV] = dist[V1]+1;
					path[w->AdjV] = path[V1];
					verQue.push(w->AdjV);
				}
			}
		}
	}

	inline LGraph GraphL::BuildGraphFromTxt()
	{

		LGraph graph =NULL;

		ifstream f("./第六讲图上/data.txt");
		if (f.is_open())
		{
			int x;
			f >> x ;
			graph = CreateGraph(x);
			f >> graph->Ne;
			cout << "图的顶点个数为：" << graph->Nv << "  图的边数为：" << graph->Ne << endl;
			if (graph->Ne>0)
			{
				Edge E = (Edge)malloc(sizeof(struct ENode));
				for (int i = 0; i < graph->Ne; i++)
				{
					f >> E->V1 >> E->V2 >> E->Weight;
					InsertEdge(graph, E, false);
					cout << "插入顶点 " << E->V1 << "向" << E->V2 <<"的边，权值为：" << E->Weight << endl;

				}
			}
		}


		f.close();
		return graph;
	}

	bool GraphL::Dijkstra(LGraph graph, int dist[], int path[], Vertex S)
	{
		bool collected[MaxVertexNum];
		/* 初始化：此处默认邻接矩阵中不存在的边用-1表示 */
		for (PtrToAdjVNode w = graph->G[S].FirstEdge; w; w = w->Next)
		{
			dist[w->AdjV] = w->Weight;
			path[w->AdjV]=S;
		}

		for (int i = 0; i < graph->Nv; i++)
		{
			collected[i] = false;
		}
		//先将起点收入集合
		dist[S] = 0;
		collected[S] = true;

		while (true)
		{
			/* V = 未被收录顶点中dist最小者 */
			Vertex V = FindMinDist(graph, dist, collected);
			if (V==-1)
			{
				break;
			}
			collected[V] = true;
			for (PtrToAdjVNode w = graph->G[V].FirstEdge; w; w = w->Next)
			{
				/* 若W是V的邻接点并且未被收录 */
				if (collected[w->AdjV]==false)
				{
					if (w->Weight < 0) //若有负数
					{
						return false;
					}
					//更新dist
					if (dist[V]+w->Weight<dist[w->AdjV])
					{
						dist[w->AdjV] = dist[V] + w->Weight;
						path[w->AdjV] = V;
					}


				}
			}
		}
		return true;
	}

	Vertex GraphL::FindMinDist(LGraph Graph, int dist[], bool collected[])
	{
		int minDist = INFINITY;
		Vertex minV;
		for (Vertex  V = 0; V < Graph->Nv; V++)
		{
			if (collected[V] == false && dist[V] < minDist)
			{
				minDist = dist[V];
				minV = V;
			}
		}
		if (minDist<INFINITY)
		{
			return minV;
		}
		else
		{
			return -1;
		}
	}
	Vertex GraphL::FindMinDist(LGraph graph, WeightType dist[])
	{
		WeightType minDist = INFINITY;
		Vertex minV;
		for (Vertex V = 0; V < graph->Nv; V++)
		{
			if (dist[V] != 0 && dist[V] < minDist)
			{
				minDist = dist[V];
				minV = V;
			}
		}
		if (minDist<INFINITY)
		{
			return minV;
		}
		else
		{
			return -1;
		}

	}

	int GraphL::Prim(LGraph graph, LGraph mst)
	{
		//将最新生成树保存成连接表存储的图mst,返回最小权重
		WeightType dist[MaxVertexNum], totalWeight;
		Vertex parent[MaxVertexNum], V, W;
		int VCount;
		Edge E;

		//初始化，默认初始点下标是0
		for (int i = 0; i < graph->Nv; i++)
		{
			dist[i] = INFINITY;
			parent[i] = 0;

		}
		for (PtrToAdjVNode w = graph->G[0].FirstEdge; w; w = w->Next)
		{
			dist[w->AdjV] = w->Weight;
		}

		totalWeight = 0;
		VCount = 0;		//初始化收录的顶点数

		//创建包含所有顶点但没有边的图。
		mst = CreateGraph(graph->Nv);
		E = (Edge)malloc(sizeof(struct ENode));//建立空的边节点

		//将初始点0收录入mst
		dist[0] = 0;
		VCount++;
		parent[0] = -1;	//当前树根是0

		while (true)
		{
			V = FindMinDist(graph, dist);
			//找未被收录的最小值
			if (V==-1)
			{
				break;
			}
			//将V及相应的边<parent[V],V>收录进mst
			E->V1 = parent[V];
			E->V2 = V;
			E->Weight = dist[V];
			InsertEdge(mst, E, false);
			totalWeight += dist[V];
			dist[V] = 0;
			VCount++;

			for (PtrToAdjVNode w = graph->G[V].FirstEdge; w; w = w->Next)
			{
				if (dist[w->AdjV]!=0)
				{
					if (w->Weight<dist[w->AdjV])
					{
						dist[w->AdjV] = w->Weight;
						parent[w->AdjV] = V;
					}
				}
			}

		}
		if (VCount<graph->Nv)
		{
			totalWeight = -1;
		}
		return totalWeight;
	}
	inline bool GraphL::TopSort(LGraph graph, Vertex topOrder[])
	{
		//对Graph进行拓扑排序，TopOrder[]顺序存储排序后的顶点下标
		int Indegree[MaxVertexNum], cnt;
		Vertex V;
		PtrToAdjVNode W;
		queue<Vertex> verQue;
		//verQue.push(S);

		//初始化Indegree[]
		for ( V = 0; V < graph->Nv; V++)
		{
			Indegree[V] = 0;
		}

		//遍历图得到Indegree[]
		for (V = 0; V < graph->Nv; V++)
		{
			for (W = graph->G[V].FirstEdge; W; W = W->Next)
			{
				Indegree[W->AdjV]++;
			}

		}

		//将所有入度为0的顶点入列
		for (V = 0; V < graph->Nv; V++)
		{
			if (Indegree[V]==0)
			{
				verQue.push(V);
			}
		}

		//下面进入拓扑排序
		cnt = 0;
		while (!verQue.empty())
		{
			V = verQue.front();
			verQue.pop();

			topOrder[cnt++] = V;
			for (W = graph->G[V].FirstEdge; W; W = W->Next)
			{
				if (--Indegree[W->AdjV]==0)
				{
					verQue.push(V);
				}
			}
		}
		if (cnt!=graph->Nv)
		{
			return false;
		}

		return true;
	}



	void GraphL::init(int num)
	{
		Visited = vector<bool>(MaxVertexNum, false);

	}
	void GraphL::test()
	{
		cout << "请选择初始化方式：手动输入请填1，从文本输入填2：" << endl;
		int tag;
		cin >> tag;
		LGraph graph;
		if (1==tag)
		{
			graph = BuildGraph();
		}
		else 
		{
			graph = BuildGraphFromTxt();
			if (graph==NULL)
			{
				cout << "图的初始化失败." << endl;
				return;
			}
		}

		while (true)
		{
			cout << "请输入数字选择哪种搜索模式，1代表深度优先搜索，2代表广度优先，-1退出：" << endl;
			int m,n = 0;
			cin >> m;
			if (-1==m)
			{
				break;
			}
			cout << "请输入数字选择从哪个数字开始搜索：" << endl;
			cin >> n;
			init(graph->Nv);

			if (1==m)
			{
				cout << "深度优先搜索：" << endl;
				DFS(graph, n, &GraphL::Visit);
			}
			else if(2 == m)
			{
				cout << "广度优先搜索：" << endl;
				BFS(graph, n, &GraphL::Visit);

			}

		}

		//无权图的最短路径算法
		int dist[MaxVertexNum];
		int path[MaxVertexNum];

		while (true)
		{
			for (int i = 0; i < graph->Nv; i++)
			{
				dist[i] = INFINITY;
				path[i] = -1;
			}
			cout << "无权图的最短路径算法" << endl;
			cout << "请输入数字选择从哪个顶点开始进入计算：" << endl;
			int n;
			cin >> n;
			if (n==-1)
			{
				break;
			}

			Unweighted(graph, dist, path, n);

			//输出
			for (int i = 0; i < graph->Nv; i++)
			{
				cout << dist[i] << "  ";
			}
			cout << endl;

		}

		//有权图的单源最短路算法
		
		while (true)
		{
			for (int i = 0; i < graph->Nv; i++)
			{
				dist[i] = INFINITY;
				path[i] = -1;
			}
			cout << "有权图的单源最短路算法,Dijkstra算法" << endl;
			cout << "请输入数字选择从哪个顶点开始进入计算：" << endl;
			int n;
			cin >> n;
			if (n == -1)
			{
				break;
			}

			Dijkstra(graph, dist, path, n);

			//输出
			for (int i = 0; i < graph->Nv; i++)
			{
				cout << dist[i] << "  ";
			}
			cout << endl;

		}


	}

}