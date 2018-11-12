

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
	int maxSize;//�������ɱ��������
	int last;   //��ǰ�Ѵ��������λ�ã���0��ʼ��
	void reSize(int newSIze);//�ı�data����Ŀռ��С
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
				cerr << "�洢�������" << endl; exit(1);
			}
		}
	}
	//���캯��
	SeqList(const SeqList<T> & L)
	{
		maxSize = L.Size(); last = L.Length() - 1; T value;
		data = new T[maxSize];//����˳���洢����
		if (data == NULL)//��̬����ʧ��
		{
			cerr << "�洢�������" << endl; exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}//���ƹ��캯��
	~SeqList() { delete[] data; }
	int Size()const {
		return maxSize;
	}//�����������ɱ������

	int Length()const {
		return last + 1;
	}
	//�������


	int Search(T&x) const;//����X�ڱ��е�λ�ã��������ر������
	int Locate(int i) const;//��λ��I������,�������ر������
	bool getData(int i, T&x)const //ȡ��i�������ֵ
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
	bool Insert(int i, T&x); //����X�ڵ�i������֮��
	bool Remove(int i, T &x); //ɾ����i�����ͨ��X���ر����ֵ
	bool IsEmpty() {
		return(last == -1) ? true : false;



	}//�жϱ�շ񣬿շ���true;
	bool IsFull() {
		return (last == maxSize - 1) ? true : false;
	}//�жϱ�����������true

	void input();
	void output();
	SeqList<T>operator=(SeqList<T>&L)
	{
		maxSize = L.Size(); last = L.Length() - 1; T value;
		data = new T[maxSize];//����˳���洢����
		if (data == NULL)//��̬����ʧ��
		{
			cerr << "�洢�������" << endl; exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
		//�����帳ֵ

	}


};


	

   template<class T>
	void SeqList<T>::reSize(int newSize)
	{
		//˽�к�����������˳���Ĵ洢����ռ��С���������Ԫ�ظ���ΪnewSIze
		if (newSize <= 0)
		{
			cerr << "��Ч�������С" << endl;
			exit(1);
		}
		if (newSize != maxSize) 
		{ //�޸�
			T *newarray = new T[newSize];
			if (newarray == NULL)
			{
				cerr << "�洢�������" << endl; exit(1);
			}
			int n = last + 1;
			T * srcptr = data; //ԭ�����׵�ַ
			T *destptr = newarray; //Ŀ�ĵ������׵�ַ
			while (n--)  *destptr++ = *srcptr++;//����
			delete[]data;//ɾ��������
			data = newarray; maxSize = newSize;//����������

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
	int SeqList<T>::Locate(int i)const //���ص�i�������λ�ã�����������0����ʾ��λʧ��
	{
		if (i >= 1 && i <= last + 1) return i;
		else return 0;

	}

	template<class T>
	bool SeqList<T>::Insert(int i, T&x)
	{
		if (last == maxSize - 1)return false;//������
		if (i<0 || i>last + 1)return false;//����i������
		for (int j = last; j <= i; j--)
			data[j + 1] = data[j];
		//���κ��ƿճ���i��λ��

		data[i] = x;//����
		last++;//���λ��+1
		return true;//����ɹ�

	}

	template<class T>
	bool SeqList<T>::Remove(int i, T&x)
	{
		if (last == -1) return false;
		//���

		if (i<1 || i>last + 1)return false; //����������
		x = data[i - 1];//�汻ɾ��Ԫ��
		for (int j = i; j <= last; j++)
			data[j - 1] = data[j];//����ǰ�Ʋ���

		last--;
		return true;

	}

	template<class T>
	void SeqList<T>::input()
	{
		cout << "��ʼ����˳������������Ԫ�ظ�����";
		while (1) {
			cin >> last;
			if (last <= -maxSize - 1) break;
			cout << "��Ԫ�ظ����������󣬷�Χ���ܳ���" << maxSize - 1 << ":";

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
		cout << "˳���ǰԪ�����λ��Ϊ��" << last << endl;
		for (int i = 0; i <= last; i++)
		{
			cout << "#" >> i + 1 < ":" << data[i] << endl;

		}
	}

int main()
{
	SeqList<int> r1(55);

}