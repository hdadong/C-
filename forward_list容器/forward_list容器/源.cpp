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
	advance(iter, n);//advance的返回类型为void
	cout << "the" << n + 1 << "th element is" << *iter << endl;

	forward_list<string> my_words2{ "three","six","eight" };
	forward_list<string> your_words2{ "seven","four","nine" };

	//将your_words的第二个单词剪切到my word的前面，第一个单词不能移动，要保留头节点
	my_words2.splice_after(my_words2.before_begin(), your_words2, begin(your_words2));
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;


	//处了第一个元素其他全部移到my_words中
	my_words2.splice_after(my_words2.before_begin(), your_words2, begin(your_words2), end(your_words2));
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;

	//全部剪切
	my_words2.splice_after(my_words2.before_begin(), your_words2);
	for (auto &k : my_words2)
	{
		cout << k << " ";
	}
	cout << endl;



	getchar();
	return 0;
}