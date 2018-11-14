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
	const E maxWeight = LLONG_MAX;//���������ֵ
	Graph(int sz = DefalultVertices);
	~Graph();
	virtual	bool insertVertex(const T&vertex);//��ͼ�в���һ������vertex���ö�����ʱû�����
	virtual bool insertEdge(int v1, int v2, int weight);//�����ɱߵ���������v1,v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1,v2)
	virtual bool removeVertex(int v);//����ɾ���Ķ�����;�еĶ��㣬��ɾȥ����v�����й��������ı�
	virtual bool removeEdge(int v1, int v2);//�����ɱߵ���������v1,v2��ͼ�еĶ��㣬����ͼ��ɾȥ��(v1,v2)
	virtual bool GraphEmpty()const {
		if (numEdges == 0)return true;
		else return false;
	}//�ж�ͼ�շ�
	bool GraphFull()const//�ж�ͼ��
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)return true;
		else return false;
	};
	int NumberOfVertices() { return numVertices; };// ���ص�ǰ������
	int NumberOfEdges() { return numEdges; };//���ص�ǰ����
	virtual int getFirstNeighbor(int v);//��������λ��V�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
	virtual int getNextNeighbor(int v1, int v2);//��������λ��Ϊv1��ĳ�ڽӶ���v2����һ���ڽӶ����λ��
	virtual E getWeight(int v1, int v2);//��������(v1,v2)�ߵ�ֵ
	virtual T getValue(int i);//ȡ����i��ֵ����������0��
	



protected:
	int maxVertices;//ͼ����󶥵���
	int numEdges;//��ǰ����
	int numVertices;//��ǰ������
	virtual int getVertexPos(T vertex);//��������vertex��ͼ�е�λ��
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
	bool insertVertex(const T&vertex);//��ͼ�в���һ������vertex���ö�����ʱû�����
	bool insertEdge(int v1, int v2, E weight);//�����ɱߵ���������v1,v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1,v2)
	bool removeVertex(int v);//����ɾ���Ķ�����;�еĶ��㣬��ɾȥ����v�����й��������ı�
	bool removeEdge(int v1, int v2);//�����ɱߵ���������v1,v2��ͼ�еĶ��㣬����ͼ��ɾȥ��(v1,v2)


	
	int getFirstNeighbor(int v);//��������λ��V�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
	int getNextNeighbor(int v1, int v2);//��������λ��Ϊv1��ĳ�ڽӶ���v2����һ���ڽӶ����λ��

private:
	T *VerticesList;//�����
	E **Edge;//����
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
	VerticesList = new T[maxVertices];//�������������
	Edge = (E **)new E*[maxVertices];//�����ڽӾ�������
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
	////��������λ��V�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
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
	//��������v��ĳ���ڽӶ���W����һ���ڽӶ���
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
	if (v < 0 || v >= numVertices)return false;//v����ͼ�У���ɾ��
	if (numVertices == 1)return false;//ֻʣ��һ�����㣬��ɾ��
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];//�������ɾ���ýڵ�
	for (i = 0; i < numVertices; i++)
	{
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)numEdges--;//��ȥ��V������ı���
	}
	for (i = 0; i < numVertices; i++)
	{
		Edge[i][v] = Edge[i][numVertices - 1];//�����һ�����v��
	}
	numVertices--;//������-1
	for (j = 0; j < numVertices; j++)//�����һ�����v��
		Edge[v][j] = Edge[numVertices][j];
	return true;
}


template<class T,class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)
{
	//����ߣ�v1,v2)��ȨֵΪcost
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
	//��ͼ��ɾȥ��(v1,v2)
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
	//ͨ��������������In����n��������Ϣ��E������߽�������
	int i, j, k, n, m;
	T e1, e2;
	E weight;
	in >> n >> m;
	for (i = 0; i < n; i++)//���������
	{
		in >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	while (i < m)
	{
		in >> e1 >> e2 >> weight;//����˵���Ϣ
		j = G.getVertexPos(e1);
		k = G.getVertexPos(e2);//�鶥���
		if (j == -1 || k == -1)
		{
			cout << "�����˵���Ϣ�����������룺" << endl;
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
	//���ͼ�����ж���ͱ���Ϣ
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
			w = G.getWeight(i, j);//ȡ����Ȩֵ
			if (w > 0 && w < maxWeight)
			{
				e1 = G.getValue(i);//��Ч
				e2 = G.getValue(j);
				out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
			}
		}

	}
	return out;
}
#endif // !GraphN
