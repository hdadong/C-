#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	deque<string> a_deque{ "i","am","sb" };
	//cout << a_deque.at(1);
	a_deque.push_front("HI,");
	/*for (auto &k :a_deque)
	{
		cout << k;
	}*/
	//cout << a_deque.at(-2);


	a_deque.emplace_front("Im");

	for (auto &k : a_deque)
	{
		cout << k;
	}
	cout << endl;
	auto iter = a_deque.insert(end(a_deque), { "ha","dou" });
	for (auto &k : a_deque)
	{
		cout << k;
	}
	cout << endl;

	//勇初始化列表替换deque容器内容
	deque<string> words{ "one","two","three","four" };
	auto init_list = { string{"seven"},string{"eight"},string{"nine"},string{"nine2"},string{"nine3"},string{"nine4"},string{"nine5"} };
	words.assign(init_list);
	for (auto &k : words)
	{
		cout << k << " ";
	}
	cout << endl;


	//用迭代器来替换
	words.assign(begin(init_list)+1, end(init_list)-1);
	for (auto &k : words)
	{
		cout << k << " ";
	}
	cout << endl;



	//用重复的对象来替换
	words.assign(8, "nine");

	auto start = begin(words);
	auto finish = end(words);
	for (; start!= finish;++start)
	{
		cout << *start << " ";
	}
	cout << endl;



	copy(istream_iterator<string>{cin}, istream_iterator<string>{}, front_inserter(words));

	copy(begin(words), end(words), ostream_iterator<string>{ cout, " " });


	 
	getchar();
	return 0;
}