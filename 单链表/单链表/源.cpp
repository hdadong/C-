

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
bool List<T>::insert(int i, T &x)//�����ڵ�i��Ԫ��֮��,i��1��ʼ����iΪ0������ڱ�ͷ
{
	if (first == NULL || i == 0)	//���Ϊ�ձ������ڱ�ͷ
	{
		LinkNode<T> *node = new LinkNode<T>(x);
		if (node == NULL) { cerr << "�洢����\n"; exit(1); }


		node->Link = first;//��Ϊ��һ���ڵ�

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
			cerr << "��Ч�Ĳ���λ��" << endl; return false;
		}
		else {
			LinkNode<T> *newNode = new LinkNode<T>(x);
			if (newNode == NULL) { cerr << "�洢�������" << endl; exit(1); }
			newNode->Link = node2->Link;
			node2->Link = newNode;
		}
	}

}








template<class T>
bool List<T>::Remove(int i, T&x)
{
	LinkNode *del, *current;
	//�������еĵ�I��Ԫ��ɾ����I��1��ʼ
	if (i <= 1) { del = first; first = first->link; }
	else
	{
		current = first;
		for (int k = 1; k < i - 1; k++)//ѭ��Ѱ�ҵ�i-1���ڵ�
			if (current == NULL)break;
			else current = current->Link;
		if (current == NULL || current->Link == NULL)//�ձ������̫��
		{
			cerr << "��Ч�Ĳ���λ��\n";
			return false;
		}
		del = current->Link;//��ʼɾ������,des
	}
	x = del->data; delete del;
	return true;
}

template<class U>
istream & operator >>(istream & in, List<U> & op)
{
	cout << "���������ȣ�";
	int size;
	in >> size;
	U data;
	for (int i = 0; i <size; i++)
	{
		cout<<"�����" << i+1 << "���ڵ�����";
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