#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
#include<string>

	int main()
{	
		vector<double>numbers{ 2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0 };
		/*make_heap(begin(numbers), end(numbers));
		numbers.push_back(11);
		push_heap(begin(numbers), end(numbers));

		*/
		make_heap(begin(numbers), end(numbers), greater<>());
	/*	numbers.push_back(1.2);
		push_heap(begin(numbers), end(numbers), greater<>());
		*/
		pop_heap(begin(numbers), end(numbers),greater<>());//����һ��Ԫ���ƶ������
		numbers.pop_back();//��VECTOR�ĳ�Ա�����Ƴ����һ��Ԫ��,������Ƴ����Ƕѣ�����Ԫ��Ϊ��
		if (is_heap(begin(numbers), end(numbers), greater<>()))
		{
			cout << "����" << endl;

		}
		auto iter = is_heap_until(begin(numbers), end(numbers), greater<>());
		//����Ƿ��в���Ԫ��Ϊ�ѣ�������Ԫ�ض�Ϊ�ѣ��򷵻�һ������������end(numbers)
		//��Ԫ������2��Ҳ�᷵�ؽ���������
		if (iter != end(numbers))
			cout << *iter<< endl;



		
		getchar();
		return 0;
}