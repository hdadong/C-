#include<iostream>
using namespace std;

template<class T>
class Stack
{
public:
	Stack() {};
	virtual void Push(const T&x) = 0;
	virtual bool Pop(T &x) = 0;
	virtual bool getTop(T&x)const = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull() const = 0;
	virtual int getSize() const = 0;
};

template<class T>
class SeqStack :public Stack<T>
{
public:
	SeqStack(int sz = 50);
	~SeqStack() { delete[]element; }
	void Push(const T&x);
	bool Pop(T&x);
	bool getTop(T&x);
	bool Isempty() const { return(top == -1) ? true : false; }
	bool IsFull()const { return(top == maxSize - 1) ? true : false; }
	int getSize()const { return top + 1; }
	void MakeEmpty() { top = -1; }
	friend ostream& operator<<(ostream &os, SeqStack<T>&s);
private:
	T *elements;
	int top;
	int maxSize;
	void overflowProcess();

};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz)
{
	elements = new T[maxSize];
	assert(element != NULL);
}

template<class T>
void SeqStack<T>::overflowProcess()
{
	T *newArray = new T[maxSize + stackIncreament];
	if (newArray = NULL) { cerr << "´æ´¢·ÖÅäÊ§Îó£¡" << endl; exit(1); }
	for (int i = 0; i <= top; i++)newArray[i] = elements[i];
	maxSize = maxSize + stackIncreament;
	delete[]elements;
	elements = newArray;
}

template<class T>
void SeqStack<T>::Push(const T&x)
{
	if (IsFull() == true)overflowProcess();
	elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T&x)
{
	if (Isempty() == true)return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::getTop(T&x)
{
	if (IsEmpty() == true)return false;
	x = elements[top];
	return true;
}

template<class T>
ostream& operator<<(ostream &os, SeqStack<T>&s)
{
	os << "top==" << s.top << endl;
	for (int i = 0; i <= s.top; i++)
	{
		os << i << ":" << s.elements[i] << endl;

	}
	return os;
}
