#pragma once
#ifndef link2.h
#define link2.h
#include<iostream>
using namespace std;
template<class T>
class List;


template<class T>
class LinkNode {
	friend class List<T>;
private:
	T data;
	LinkNode *Link;
	LinkNode(T x) { data = x };


};

template<class T>
bool List<T>::insert(int i, T &x)//插入在第i个元素之后,i从1开始，若i为0则插入在表头
{
	if (fist == null || i == 0)	//如果为空表或插入在表头
	{
		LinkNode *node = new LinkNode(x);
		if (node == null) { cerr << "存储错误！\n"; exit(1); }
		

		node->Link = first;//成为第一个节点

		first = node;
		
	}

	else
	{
		LinkNode *node2 = first;
		for (int k = 1; k < i; k++)
		{
			if (node2 = null) break;
			else node2 = node2->Link;
		}
	}

}





template<class T>
class List {

public:
	bool insert(int i, T &x);
	bool Remove(int i, T& x);
	List(LinkNode *sbzhj)
	{
		first = sbzhj;
	}
	List(){}
private:
	LinkNode *first=NULL;

};


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
			else current = current->link;
		if(current==NULL||current->link==NULL)//空表或者琏太短
		{
			cerr >> "无效的插入位置\n";
			return false;
		}
		del = current->link;//开始删除操作,del用来保存要被删除节点的信息
		current->link = del->link;
	}
	x = del->data; delete del;
	return true;
}



#endif // !link.h