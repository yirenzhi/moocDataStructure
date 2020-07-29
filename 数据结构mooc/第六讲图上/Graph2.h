#pragma once
#include "../base.h"
#include <fstream>

#include <direct.h>
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
		int Nv;//	������
		int Ne;//	����
		AdjList G;
	};

	typedef PtrToGNode LGraph;

	//ͼ���ڽӱ��ʾ��
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
		void init(int num);	//����֮ǰ�ĳ�ʼ������Ҫ������Visitedȫ��ֵΪfalse

		/* �ڽӱ�洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
		/* dist[]��path[]ȫ����ʼ��Ϊ-1 */
		void Unweighted(LGraph Graph, int dist[], int path[], Vertex S);
		LGraph BuildGraphFromTxt();
		//��Ȩͼ�ĵ�Դ���·�㷨
		bool Dijkstra(LGraph Graph, int dist[], int path[], Vertex S);
		Vertex FindMinDist(LGraph Graph, int dist[], bool collected[]);

		//��С���������⣬
		int Prim(LGraph graph, LGraph mst);
		Vertex FindMinDist(LGraph Graph, WeightType dist[]);

		//��������T=O(|V|+|Es|)
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
		cout << "���붥�����" << endl;
		cin >> Nv;

		LGraph graph = CreateGraph(Nv);
		cout << "���������" << endl;
		cin >> graph->Ne;
		if (graph->Ne>0)
		{
			Edge E = (Edge)malloc(sizeof(struct ENode));
			cout << "������� �յ� Ȩ�صĸ�ʽ���롣" << endl;;
			for (int i = 0; i < graph->Ne; i++)
			{
				cin >> E->V1 >> E->V2 >> E->Weight;
				InsertEdge(graph, E);
				cout << "������ϡ�" << endl;

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
				if (!Visited[w->AdjV])
				{
					this->Visit(w->AdjV);
					verQue.push(w->AdjV);
				}
			}
		}
	}
	//��Ȩͼ�����·���㷨
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

		ifstream f("./������ͼ��/data.txt");
		if (f.is_open())
		{
			int x;
			f >> x ;
			graph = CreateGraph(x);
			f >> graph->Ne;
			cout << "ͼ�Ķ������Ϊ��" << graph->Nv << "  ͼ�ı���Ϊ��" << graph->Ne << endl;
			if (graph->Ne>0)
			{
				Edge E = (Edge)malloc(sizeof(struct ENode));
				for (int i = 0; i < graph->Ne; i++)
				{
					f >> E->V1 >> E->V2 >> E->Weight;
					InsertEdge(graph, E, false);
					cout << "���붥�� " << E->V1 << "��" << E->V2 <<"�ıߣ�ȨֵΪ��" << E->Weight << endl;

				}
			}
		}


		f.close();
		return graph;
	}

	bool GraphL::Dijkstra(LGraph graph, int dist[], int path[], Vertex S)
	{
		bool collected[MaxVertexNum];
		/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���-1��ʾ */
		for (PtrToAdjVNode w = graph->G[S].FirstEdge; w; w = w->Next)
		{
			dist[w->AdjV] = w->Weight;
			path[w->AdjV]=S;
		}

		for (int i = 0; i < graph->Nv; i++)
		{
			collected[i] = false;
		}
		//�Ƚ�������뼯��
		dist[S] = 0;
		collected[S] = true;

		while (true)
		{
			/* V = δ����¼������dist��С�� */
			Vertex V = FindMinDist(graph, dist, collected);
			if (V==-1)
			{
				break;
			}
			collected[V] = true;
			for (PtrToAdjVNode w = graph->G[V].FirstEdge; w; w = w->Next)
			{
				/* ��W��V���ڽӵ㲢��δ����¼ */
				if (collected[w->AdjV]==false)
				{
					if (w->Weight < 0) //���и���
					{
						return false;
					}
					//����dist
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
		//��������������������ӱ�洢��ͼmst,������СȨ��
		WeightType dist[MaxVertexNum], totalWeight;
		Vertex parent[MaxVertexNum], V, W;
		int VCount;
		Edge E;

		//��ʼ����Ĭ�ϳ�ʼ���±���0
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
		VCount = 0;		//��ʼ����¼�Ķ�����

		//�����������ж��㵫û�бߵ�ͼ��
		mst = CreateGraph(graph->Nv);
		E = (Edge)malloc(sizeof(struct ENode));//�����յı߽ڵ�

		//����ʼ��0��¼��mst
		dist[0] = 0;
		VCount++;
		parent[0] = -1;	//��ǰ������0

		while (true)
		{
			V = FindMinDist(graph, dist);
			//��δ����¼����Сֵ
			if (V==-1)
			{
				break;
			}
			//��V����Ӧ�ı�<parent[V],V>��¼��mst
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
		//��Graph������������TopOrder[]˳��洢�����Ķ����±�
		int Indegree[MaxVertexNum], cnt;
		Vertex V;
		PtrToAdjVNode W;
		queue<Vertex> verQue;
		//verQue.push(S);

		//��ʼ��Indegree[]
		for ( V = 0; V < graph->Nv; V++)
		{
			Indegree[V] = 0;
		}

		//����ͼ�õ�Indegree[]
		for (V = 0; V < graph->Nv; V++)
		{
			for (W = graph->G[V].FirstEdge; W; W = W->Next)
			{
				Indegree[W->AdjV]++;
			}

		}

		//���������Ϊ0�Ķ�������
		for (V = 0; V < graph->Nv; V++)
		{
			if (Indegree[V]==0)
			{
				verQue.push(V);
			}
		}

		//���������������
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
		cout << "��ѡ���ʼ����ʽ���ֶ���������1�����ı�������2��" << endl;
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
				cout << "ͼ�ĳ�ʼ��ʧ��." << endl;
				return;
			}
		}

		while (true)
		{
			cout << "����������ѡ����������ģʽ��1�����������������2���������ȣ�-1�˳���" << endl;
			int m,n = 0;
			cin >> m;
			if (-1==m)
			{
				break;
			}
			cout << "����������ѡ����ĸ����ֿ�ʼ������" << endl;
			cin >> n;
			init(graph->Nv);

			if (1==m)
			{
				cout << "�������������" << endl;
				DFS(graph, n, &GraphL::Visit);
			}
			else if(2 == m)
			{
				cout << "�������������" << endl;
				BFS(graph, n, &GraphL::Visit);

			}

		}

		//��Ȩͼ�����·���㷨
		int dist[MaxVertexNum];
		int path[MaxVertexNum];

		while (true)
		{
			for (int i = 0; i < graph->Nv; i++)
			{
				dist[i] = INFINITY;
				path[i] = -1;
			}
			cout << "��Ȩͼ�����·���㷨" << endl;
			cout << "����������ѡ����ĸ����㿪ʼ������㣺" << endl;
			int n;
			cin >> n;
			if (n==-1)
			{
				break;
			}

			Unweighted(graph, dist, path, n);

			//���
			for (int i = 0; i < graph->Nv; i++)
			{
				cout << dist[i] << "  ";
			}
			cout << endl;

		}

		//��Ȩͼ�ĵ�Դ���·�㷨
		
		while (true)
		{
			for (int i = 0; i < graph->Nv; i++)
			{
				dist[i] = INFINITY;
				path[i] = -1;
			}
			cout << "��Ȩͼ�ĵ�Դ���·�㷨,Dijkstra�㷨" << endl;
			cout << "����������ѡ����ĸ����㿪ʼ������㣺" << endl;
			int n;
			cin >> n;
			if (n == -1)
			{
				break;
			}

			Dijkstra(graph, dist, path, n);

			//���
			for (int i = 0; i < graph->Nv; i++)
			{
				cout << dist[i] << "  ";
			}
			cout << endl;

		}


	}

}