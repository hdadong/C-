#include<iostream>
#include<forward_list>
#include<iterator>
#include<string>
using namespace std;
int main()
{
	forward_list<string>my_words{ "three","six","eight" };
	auto count = distance(begin(my_words), end(my_words));
	cout << count << endl;


	forward_list<int> data{ 10,21,43,87,175,351 };
	auto iter = begin(data);
	size_t n{ 3 };
	advance(iter, n);//advance�ķ�������Ϊvoid
	cout << "the" << n + 1 << "th element is" << *iter << endl;

	forward_list<string> my_words2{ "three","six","eight" };
	forward_list<string> your_words2{ "seven","four","nine" };

	//��your_words�ĵڶ������ʼ��е�my word��ǰ�棬��һ�����ʲ����ƶ���Ҫ����ͷ�ڵ�
	my_words2.splice_after(my_words2.before_begin(), your_words2, begin(your_words2));
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;


	//���˵�һ��Ԫ������ȫ���Ƶ�my_words��
	my_words2.splice_after(my_words2.before_begin(), your_words2, begin(your_words2), end(your_words2));
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;

	//ȫ������
	my_words2.splice_after(my_words2.before_begin(), your_words2);
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;



	getchar();
	return 0;
}