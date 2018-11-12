#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *rLink, *lLink;
	Node(int i)
	{
		data = i;
		rLink = NULL;
		lLink = NULL;
	}
	
};

class List
{
public:
	List(int n)
	{
		size = n;
		first = new Node(0);
		Node *p;
		p = first;
		for (int i = 1; i <= n; i++)
		{
			
			p->rLink = new Node(i);
			p->rLink->lLink = p;//p����һ���ڵ����ڵ���ΪP

			p = p->rLink;//��P�ƶ�����һ���ڵ�

			if (i == n)//��β����
			{
				p->rLink = first;
				first->lLink = p;
			}
			
		}
	}
	~List()
	{
		Node *p = first;
		for (int i = 1; i <= size; i++)
		{
			p = p->rLink;
			delete p->lLink;
			

		}
		delete p;
	}
	
	int size;
	Node *first;
};


int main()
{
	int n, m;
	cout << "����n��M";
	cin >> n >> m;


	List a(n);
	Node *p, *pre;
	p = a.first->rLink;
	for (int i = 1; i <= n - 1; i++)//n-1����
	{
		for (int j = 1; j < m; j++)//��m����
		{
			
			p = p->rLink;
			if (p == a.first)//����ͷ�ڵ�
			{
				p = p->rLink;
			}
		}
		p->lLink->rLink = p->rLink;//�ѱ���Ϊm���� ��ǰ���Ǹ��˵ĺ�һ���ڵ���Ϊ��M���˵ĺ�һ���ڵ�
		p->rLink->lLink = p->lLink;//�ѱ���ΪM���� �����Ǹ��˵� ǰһ���ڵ���Ϊ ����ΪM���˵�ǰһ���ڵ�
		pre = p->rLink;
		a.size--;
		cout << "���ӵ���" << p->data << endl;
		delete p;
		p = pre;
		if (p == a.first)//����ͷ�ڵ�
		{
			p = p->rLink;
		}
		if (i == n - 1)
		{
			cout << "���һ������" << p->data;
		}


	}
	//cout << a.first->data;

	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}