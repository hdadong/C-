#include<iostream>
using namespace std;
/*
template<class T>
class LinkNode
{
public:
	LinkNode() { first = last = NULL; }
	LinkNode(T x) { data = x; }


private:
	LinkNode *first;
	LinkNode *last;
	T data;



};


template<class T>
class Link
{

public:
	Link()
	{
		first1 = last1 = NULL;

	}

	void insert(T x)
	{
		LinkNode<int> r1 = new LinkNode<int>(x);
			length++;
		if (length == 1)
		{
			first1 = r1;
			last1 = r1;

		}
		else
		{
			last1->last = r1;
			r1.first = last1;
			last1 = r1;
			last1->last = first1;
			
		}
			

	}

private:
	LinkNode<T> *first1, *last1;
	int length = 0;

};

int main()
{
	Link<int> r1;
	r1.insert(5);
	r1.insert(10);
	
}