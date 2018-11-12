#include<iostream>
using namespace std;
template<class T>
class LinearList
{
public:
	LinearList();
	LinearList();
	virtual int size()  const = 0;
	virtual int Length() const = 0;
	virtual int Search(T &x) const = 0;
	virtual int Locate(int i) const = 0;
	virtual bool getData(int i, T&x) const = 0;
	virtual void setData(omt o, T&x) = 0;
	virtual bool Insert(int i, T&x) = 0;
	virtual bool Remove(int i, T&x) = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull()const = 0;
	virtual void Sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T>operator=(LinearList<T>&L) = 0;
};

template<class T>
struct CircLinkNode
{
	T data;
	CircLinkNode<T> *link;
	CircLinkNode(CircLinkNode<T>*next = NULL) :link(next) {}
	CircLinkNode(CircLinkNode<T>*next = NULL) :data(d), link(next)){}

};

template<class T>
class CirList :public LinearList<T> {
public:
	CirList(const T&x);
	CirList(CirList<T>&L);
	~CirList();
	int Length()const;
	bool IsEmpty() { return first->link == first ? true : false; }
	CircLinkNode<T>*getHead()const;
	void setHead(CircLinkNode<T>*p);//设置附加头节点地址
	CircLinkNode<T>*Search(T x); //搜索含数据X的元素
	CircLinkNode<T>*Locate(int i);//搜索第i个元素的地址
		T*getData(int i);//取出第i个元素的值
		void setData(int i, T&x); //用X修改第i个元素的值
		bool Insert(int i, T&x);//在第I个元素后插入X
		bool Remove(int i, T&x);//删除第i个元素，x返回该元素的值
private:
	CircLinkNode<T> *first, *last;
};

template<class  T>
CirList<T>::CirList(const T&x)
{
	
}