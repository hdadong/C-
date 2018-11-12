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
bool List<T>::insert(int i, T &x)//�����ڵ�i��Ԫ��֮��,i��1��ʼ����iΪ0������ڱ�ͷ
{
	if (fist == null || i == 0)	//���Ϊ�ձ������ڱ�ͷ
	{
		LinkNode *node = new LinkNode(x);
		if (node == null) { cerr << "�洢����\n"; exit(1); }
		

		node->Link = first;//��Ϊ��һ���ڵ�

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
	//�������еĵ�I��Ԫ��ɾ����I��1��ʼ
	if (i <= 1) { del = first; first = first->link; }
	else
	{
		current = first;
		for (int k = 1; k < i - 1; k++)//ѭ��Ѱ�ҵ�i-1���ڵ�
			if (current == NULL)break;
			else current = current->link;
		if(current==NULL||current->link==NULL)//�ձ������̫��
		{
			cerr >> "��Ч�Ĳ���λ��\n";
			return false;
		}
		del = current->link;//��ʼɾ������,del��������Ҫ��ɾ���ڵ����Ϣ
		current->link = del->link;
	}
	x = del->data; delete del;
	return true;
}



#endif // !link.h