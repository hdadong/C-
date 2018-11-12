

#include<iostream>
using namespace std;
template<class T>
class List;


template<class T>
class LinkNode {
public:
	friend class List<T>;
	LinkNode(T x) { data = x; }
	LinkNode() {}
private:
	T data;
	LinkNode *Link;


};



template<class T>
class List {
	template<class U>
	friend istream& operator >>(istream &, List<U> &);
public:
	bool insert(int i, T &x);
	bool Remove(int i, T& x);
	List(LinkNode<T> *sbzhj)
	{
		first = sbzhj;
	}
	List() {}

	
private:
	LinkNode<T> *first = NULL;

};



template<class T>
bool List<T>::insert(int i, T &x)//插入在第i个元素之后,i从1开始，若i为0则插入在表头
{
	if (first == NULL || i == 0)	//如果为空表或插入在表头
	{
		LinkNode<T> *node = new LinkNode<T>(x);
		if (node == NULL) { cerr << "存储错误！\n"; exit(1); }


		node->Link = first;//成为第一个节点

		first = node;

	}

	else
	{
		LinkNode<T> *node2 = first;
		for (int k = 1; k < i; k++)
		{
			if (node2 = NULL) break;
			else node2 = node2->Link;
		}
		if(node2==NULL)
		{
			cerr << "无效的插入位置" << endl; return false;
		}
		else {
			LinkNode<T> *newNode = new LinkNode<T>(x);
			if (newNode == NULL) { cerr << "存储分配错误" << endl; exit(1); }
			newNode->Link = node2->Link;
			node2->Link = newNode;
		}
	}

}








template<class T>
bool List<T>::Remove(int i, T&x)
{
	LinkNode *del, *current;
	//将链表中的第I个元素删除，I从1开始
	if (i <= 1) { del = first; first = first->link; }
	else
	{
		current = first;
		for (int k = 1; k < i - 1; k++)//循环寻找第i-1个节点
			if (current == NULL)break;
			else current = current->Link;
		if (current == NULL || current->Link == NULL)//空表或者琏太短
		{
			cerr << "无效的插入位置\n";
			return false;
		}
		del = current->Link;//开始删除操作,des
	}
	x = del->data; delete del;
	return true;
}

template<class U>
istream & operator >>(istream & in, List<U> & op)
{
	cout << "输入链表长度：";
	int size;
	in >> size;
	U data;
	for (int i = 0; i <size; i++)
	{
		cout<<"输入第" << i+1 << "个节点数据";
		in >> data;
		op.insert(i,data);
	}
	
	return in;
}




int main()
{
	LinkNode<int> *p = new LinkNode<int>;
	List<int> r1;
	cin >> r1;

	getchar();
	return 0;
	
}