#pragma once
#ifndef GraphN
#define GraphN
#include<limits.h>
#include<ostream>
using namespace std;

template<class T,class E>
class Graph
{
public:
	const E maxWeight = LLONG_MAX;//代表无穷的值
	Graph(int sz = DefalultVertices);
	~Graph();
	virtual	bool insertVertex(const T&vertex);//在图中插入一个顶点vertex，该定点暂时没有入边
	virtual bool insertEdge(int v1, int v2, int weight);//若构成边的两个顶点v1,v2是图中的顶点，则在图中插入一条边（v1,v2)
	virtual bool removeVertex(int v);//若被删除的顶点是途中的顶点，则删去顶点v和所有关联到它的边
	virtual bool removeEdge(int v1, int v2);//若构成边的两个顶点v1,v2是图中的顶点，则在图中删去边(v1,v2)
	virtual bool GraphEmpty()const {
		if (numEdges == 0)return true;
		else return false;
	}//判断图空否
	bool GraphFull()const//判断图满
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)return true;
		else return false;
	};
	int NumberOfVertices() { return numVertices; };// 返回当前顶点数
	int NumberOfEdges() { return numEdges; };//返回当前边数
	virtual int getFirstNeighbor(int v);//给出顶点位置V的第一个邻接顶点的位置，如果找不到，则函数返回-1
	virtual int getNextNeighbor(int v1, int v2);//给出顶点位置为v1的某邻接顶点v2的下一个邻接顶点的位置
	virtual E getWeight(int v1, int v2);//函数返回(v1,v2)边的值
	virtual T getValue(int i);//取顶点i的值，不合理返回0；
	



protected:
	int maxVertices;//图中最大顶点数
	int numEdges;//当前边数
	int numVertices;//当前顶点数
	virtual int getVertexPos(T vertex);//给出顶点vertex在图中的位置
};



template<class T,class E>
class Graphmtx :public Graph<T, E>
{
	friend istream&operator >>(istream&in, Graphmtx<T, E>&G);
	friend ostream& operator<<(ostream&ot, Graphmtx<T, E>&G);
public:
	Graphmtx(int sz = DefaultVertices);
	~Graphmtx() { delete[]VerticesList; delete[]Edge; };
	T getValue(int i) { return i >= 0 && i <= numVertices ? VerticesList[i] : NULL; };
	E getWeight(int v1, int v2) { return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; };
	bool insertVertex(const T&vertex);//在图中插入一个顶点vertex，该定点暂时没有入边
	bool insertEdge(int v1, int v2, E weight);//若构成边的两个顶点v1,v2是图中的顶点，则在图中插入一条边（v1,v2)
	bool removeVertex(int v);//若被删除的顶点是途中的顶点，则删去顶点v和所有关联到它的边
	bool removeEdge(int v1, int v2);//若构成边的两个顶点v1,v2是图中的顶点，则在图中删去边(v1,v2)


	
	int getFirstNeighbor(int v);//给出顶点位置V的第一个邻接顶点的位置，如果找不到，则函数返回-1
	int getNextNeighbor(int v1, int v2);//给出顶点位置为v1的某邻接顶点v2的下一个邻接顶点的位置

private:
	T *VerticesList;//顶点表
	E **Edge;//矩阵
	int getVertexPos(T vertex)
	{
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == Vertex) return i;
		return -1;
	}
};

template<class T,class E>
Graphmtx<T, E>::Graphmtx(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];//创建顶点表数组
	Edge = (E **)new E*[maxVertices];//创建邻接矩阵数组
	for (i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	for (i = 0; i < maxVertices; i++)
	{
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) > 0:maxWeight;
	}
}

template<class T,class E>
int Graphmtx<T, E>::getFirstNeighbor(int v)
{
	////给出顶点位置V的第一个邻接顶点的位置，如果找不到，则函数返回-1
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight) return col;
		}
	}
	
	return -1;
}

template<class T,class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w)
{
	//给出顶点v的某个邻接顶点W的下一个邻接顶点
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < numberVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)return col;
		}
	}
	return -1;
}

template<class T,class E>
bool Graphmtx<T, E>::insertVertex(const T &vertex)
{
	if (numVertices == maxVertices)return false;
	VerticesList[numVertices++] = vertex;
	return true;
}


template<class T,class E>
bool Graphmtx<T, E>::removeVertex(int v)
{
	if (v < 0 || v >= numVertices)return false;//v不在图中，不删除
	if (numVertices == 1)return false;//只剩下一个顶点，不删除
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];//顶点表中删除该节点
	for (i = 0; i < numVertices; i++)
	{
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)numEdges--;//减去与V相关联的边数
	}
	for (i = 0; i < numVertices; i++)
	{
		Edge[i][v] = Edge[i][numVertices - 1];//用最后一列填补第v列
	}
	numVertices--;//顶点数-1
	for (j = 0; j < numVertices; j++)//用最后一行填补第v行
		Edge[v][j] = Edge[numVertices][j];
	return true;
}


template<class T,class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)
{
	//插入边（v1,v2)，权值为cost
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] = maxWeight) {
		Edge[v1][v2] = Edge[2][1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}

template<class T,class E>
bool Graphmtx<T, E>::removeEdge(int v1, int v2)
{
	//在图中删去边(v1,v2)
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else return false;
}


template<class T,class E>
istream &operator>>(istream&in, Graphmtx<T, E>&G)
{
	//通过从输入流对象In输入n个顶点信息和E条无向边建立矩阵
	int i, j, k, n, m;
	T e1, e2;
	E weight;
	in >> n >> m;
	for (i = 0; i < n; i++)//建立顶点表
	{
		in >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	while (i < m)
	{
		in >> e1 >> e2 >> weight;//输入端点信息
		j = G.getVertexPos(e1);
		k = G.getVertexPos(e2);//查顶点号
		if (j == -1 || k == -1)
		{
			cout << "边两端点信息有误，重新输入：" << endl;
		}
		else {
			G.insertEdge(j, k, weight); i++;
		}

	}
	return in;
}


template<class T,class E>
ostream&operator<<(ostream&out, Graphmtx<T, E>&G)
{
	//输出图的所有顶点和边信息
	int i, j, n, m;
	T e1, e2;
	E w;
	n = G.NumberOfVertices();
	m = G.NumberOfEdges();
	out << n << "," << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			w = G.getWeight(i, j);//取边上权值
			if (w > 0 && w < maxWeight)
			{
				e1 = G.getValue(i);//有效
				e2 = G.getValue(j);
				out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
			}
		}

	}
	return out;
}
#endif // !GraphN
