

#include<iostream>
using namespace std;

template<class T>
class LinearList
{
public:
	LinearList();

	virtual int size()  const = 0;
	virtual int Length() const = 0;
	virtual int Search(T &x) const = 0;
	virtual int Locate(int i) const = 0;
	virtual bool getData(int i, T&x) const = 0;
	virtual void setData(int i, T&x) = 0;
	virtual bool Insert(int i, T&x) = 0;
	virtual bool Remove(int i, T&x) = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull()const = 0;
	virtual void Sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T>operator=(LinearList<T>&L) = 0;
};


const int defaultSize = 100;
template<class T>
class SeqList :public LinearList<T>
{
protected:
	T *data;
	int maxSize;//最大可容纳表项的项数
	int last;   //当前已存表项的最后位置（从0开始）
	void reSize(int newSIze);//改变data数组的空间大小
public:
	SeqList(int sz)
	{
		if (sz > 0)
		{
			maxSize = sz;
			last = -1;
			data = new T[maxSize];
			if (data == NULL)
			{
				cerr << "存储分配错误！" << endl; exit(1);
			}
		}
	}
	//构造函数
	SeqList(const SeqList<T> & L)
	{
		maxSize = L.Size(); last = L.Length() - 1; T value;
		data = new T[maxSize];//创建顺序表存储数组
		if (data == NULL)//动态分配失败
		{
			cerr << "存储分配错误" << endl; exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}//复制构造函数
	~SeqList() { delete[] data; }
	int Size()const {
		return maxSize;
	}//计算最大可容纳表项个数

	int Length()const {
		return last + 1;
	}
	//计算表长度


	int Search(T&x) const;//搜索X在表中的位置，函数返回表项序号
	int Locate(int i) const;//定位第I个表项,函数返回表项序号
	bool getData(int i, T&x)const //取第i个表项的值
	{
		if (i > 0 && i <= last + 1)
		{
			x = data[i - 1]; return true;
		}
		else return false;

	}
	bool setData(int i, T&x)
	{
		if (i > 0 && i <= last + 1)data[i - 1] = x;
	}
	bool Insert(int i, T&x); //插入X在第i个表项之后
	bool Remove(int i, T &x); //删除第i个表项，通过X返回表项的值
	bool IsEmpty() {
		return(last == -1) ? true : false;



	}//判断表空否，空返回true;
	bool IsFull() {
		return (last == maxSize - 1) ? true : false;
	}//判断表满否，满返回true

	void input();
	void output();
	SeqList<T>operator=(SeqList<T>&L)
	{
		maxSize = L.Size(); last = L.Length() - 1; T value;
		data = new T[maxSize];//创建顺序表存储数组
		if (data == NULL)//动态分配失败
		{
			cerr << "存储分配错误" << endl; exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
		//表整体赋值

	}


};


	

   template<class T>
	void SeqList<T>::reSize(int newSize)
	{
		//私有函数：：扩充顺序表的存储数组空间大小，新数组的元素个数为newSIze
		if (newSize <= 0)
		{
			cerr << "无效的数组大小" << endl;
			exit(1);
		}
		if (newSize != maxSize) 
		{ //修改
			T *newarray = new T[newSize];
			if (newarray == NULL)
			{
				cerr << "存储分配错误" << endl; exit(1);
			}
			int n = last + 1;
			T * srcptr = data; //原数组首地址
			T *destptr = newarray; //目的的数组首地址
			while (n--)  *destptr++ = *srcptr++;//复制
			delete[]data;//删除老数组
			data = newarray; maxSize = newSize;//复制新数组

		}

	}

	template<class T>
	int SeqList<T>::Search(T &x)const
	{
		for (int i = 0; i <= last; i++)
		{
			if (data[i] == x)return i + 1;
		}
		return 0;
	}

	template<class T>
	int SeqList<T>::Locate(int i)const //返回第i个表项的位置，否则函数返回0，表示定位失败
	{
		if (i >= 1 && i <= last + 1) return i;
		else return 0;

	}

	template<class T>
	bool SeqList<T>::Insert(int i, T&x)
	{
		if (last == maxSize - 1)return false;//表满了
		if (i<0 || i>last + 1)return false;//参数i不合理
		for (int j = last; j <= i; j--)
			data[j + 1] = data[j];
		//依次后移空出第i个位置

		data[i] = x;//插入
		last++;//最后位置+1
		return true;//插入成功

	}

	template<class T>
	bool SeqList<T>::Remove(int i, T&x)
	{
		if (last == -1) return false;
		//表空

		if (i<1 || i>last + 1)return false; //参数不合理
		x = data[i - 1];//存被删除元素
		for (int j = i; j <= last; j++)
			data[j - 1] = data[j];//依次前移补齐

		last--;
		return true;

	}

	template<class T>
	void SeqList<T>::input()
	{
		cout << "开始建立顺序表，请输入表中元素个数：";
		while (1) {
			cin >> last;
			if (last <= -maxSize - 1) break;
			cout << "表元素个数输入有误，范围不能超过" << maxSize - 1 << ":";

		}
		for (int i = 0; i <= last; i++)
		{
			cin >> data[i];
			cout << i + 1 << endl;

		}
	}

	template<class T>
	void SeqList<T>::output()
	{
		cout << "顺序表当前元素最后位置为：" << last << endl;
		for (int i = 0; i <= last; i++)
		{
			cout << "#" >> i + 1 < ":" << data[i] << endl;

		}
	}

int main()
{
	SeqList<int> r1(55);

}