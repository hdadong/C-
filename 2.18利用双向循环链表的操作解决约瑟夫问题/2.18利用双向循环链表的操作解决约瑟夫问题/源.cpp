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
			p->rLink->lLink = p;//p的下一个节点的左节点设为P

			p = p->rLink;//把P移动到下一个节点

			if (i == n)//首尾相连
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
	cout << "输入n和M";
	cin >> n >> m;


	List a(n);
	Node *p, *pre;
	p = a.first->rLink;
	for (int i = 1; i <= n - 1; i++)//n-1个人
	{
		for (int j = 1; j < m; j++)//第m个人
		{
			
			p = p->rLink;
			if (p == a.first)//跳过头节点
			{
				p = p->rLink;
			}
		}
		p->lLink->rLink = p->rLink;//把报数为m的人 的前面那个人的后一个节点设为第M个人的后一个节点
		p->rLink->lLink = p->lLink;//把报数为M的人 后面那个人的 前一个节点设为 报数为M的人的前一个节点
		pre = p->rLink;
		a.size--;
		cout << "出队的是" << p->data << endl;
		delete p;
		p = pre;
		if (p == a.first)//跳过头节点
		{
			p = p->rLink;
		}
		if (i == n - 1)
		{
			cout << "最后一个人是" << p->data;
		}


	}
	//cout << a.first->data;

	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}