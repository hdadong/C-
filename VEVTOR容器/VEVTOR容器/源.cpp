#include<vector>
#include<iostream>
#include<array>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	vector<double >value;
	value.reserve(20);//没有元素

	vector<unsigned int>prime{ 2u,3u,4u,5u,7u,11u,13u,17u,19u };
	
	vector<double>values2(20);//默认值都为0

	vector<long>number(20, 99L);
	//20个元素的值都为99L


	//将array的元素复制到vector中
	array<string, 5> words2{ "one","two","three","four","five" };
	vector<string>words_copy{ begin(words2),end(words2) };
	for (const auto&w : words2)
	{
		cout << w << endl;
	}
	//用移动迭代器将array的元素移动到vector中,移动之后array为空字符
	vector<string>words_copy2(make_move_iterator(begin(words2)), make_move_iterator(end(words2)));
	for (const auto&w : words2)
	{
		cout << w << endl;
	}


	vector<size_t>primes{ 2,3,4,5,6,7 };
	cout << primes.capacity();
	cout << primes.size();

	primes.push_back(8);
	cout << primes.capacity();//会增加原来的一半
	cout << primes.size();//会加一

	primes.resize(10, 99);
	for (auto it = rbegin(primes); it != rend(primes); it++)
	{
		cout << *it << endl;
	}


	//会删去后面的元素
	primes.resize(5);
	for (auto it = rbegin(primes); it != rend(primes); it++)
	{
		cout << *it << endl;
	}


	//返回第一个和最后一个元素的引用
	primes.front() = 99;
	cout << primes[0] << endl;
	primes.back() = 55;
	cout << primes[primes.size() - 1] << endl;

	//返回一个指向数组的指针
	auto pdata = primes.data();//现在Pdata是*int类型的指针

	cout << pdata[0] << endl;
/*
	vector<string>words3;
	words3.reserve(10);
	cout << "输入单词并用空格分开，输入CTRL+Z结束输入" << endl;
	copy(istream_iterator<string>{cin}, istream_iterator<string>(), back_inserter(words3));
	cout << "开始排序";
	bool out_of_order{ false };

	auto last = end(words3);
	while (true)
	{
		for (auto first = begin(words3) + 1; first != last; ++first)
		{
			if (*(first - 1) > *first)
			{
				swap(*first, *(first - 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)break;
		out_of_order = false;
	}
	cout << "单词升序" << endl;

	copy(begin(words3), end(words3), ostream_iterator<string>{cout, " "});
	cout << endl;

	vector<string>words3_copy{ make_move_iterator(begin(words3)),make_move_iterator(end(words3)) };
	cout << "当移动婉单词后，word_copy包含：" << endl;

	cout << "单词数量是" << words3.size() << endl;

	if (words3.front().empty())
	{
		cout << "第一个元素是空的" << endl;
	}
	cout << "第一个元素是" << words3.front() << endl;


	*/
	vector<string>words;
	words.push_back(string("abcd"));

	words.emplace_back("abs");//对象会在容器中直接生成，而不是先单独生成对象再把它作为参数传入
	words.emplace_back("alleged", 2, 3);//从索引2开始的三个字符

	auto iter = words.emplace(++begin(words), 5, 'A');//第一个参数是迭代器，确定对象生成位置，生成5个A
	//emplace会返回一个指向插入元素的迭代器
	words.emplace(++iter, "$$$$");
	for (const auto&k : words)
	{
		cout << k << " ";

	}
	cout << endl;

	//insert有两个重载版本，第二个参数不同，一个是const T&直接复制对象过去容器，另一个版本是T&&右值引用，把第二个参数移动过去
	 iter = words.insert(++begin(words), "two");//这里会调用insert右值引用的版本,two这个临时对象会被移动插入到容器中而不是复制过去
	//emplace更高效，不需要生成临时对象two
	//正向迭代器则会插入在迭代器指向元素之前，反向则相反
	 for (const auto&k : words)
	 {
		 cout << k << " ";
	 }
	 cout << endl;




	string more[]{ "five","six","seven" };
	iter = words.insert(--end(words), begin(more), end(more));//返回的迭代器指向插入的第一个元素five
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;



	//在末尾插入
	iter = words.insert(end(words), "ten");
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;


	//插入多个元素
	iter = words.insert(cend(words) , 2, "nine");//cend是const迭代器
	for (const auto&k : words)
	{
		cout << k << " " ;
	}
	cout << endl;
	

	cout << "现有容量为：" << words.capacity() << endl;
	words.pop_back();
	words.shrink_to_fit();
	cout << "现有容量为：" << words.capacity() << endl;
	iter = words.insert(cend(words), 2, "nine");//cend是const迭代器
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;


	iter = words.erase(begin(words)+1);//删除第二个元素
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;

	iter = words.erase(begin(words) + 1, begin(words) + 3);//删除第二个和第三个元素
	for (const auto&k :words)
	{
		cout << k << " ";
	}
	cout << endl;

	auto iter2 = words.insert(begin(words)+1, "nine");
	iter2 = words.insert(begin(words) + 3, "nine");
	iter = words.insert(cend(words), 2, "nine");//cend是const迭代器
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;
	/*
	iter = remove(begin(words), end(words), "nine");

	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;
	words.erase(iter, end(words));

	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;
	*/
	//移除同样的元素
	words.erase(remove(begin(words), end(words), "nine"), end(words));
	for (const auto&k : words)
	{
		cout << k << " ";
	}


	vector<size_t>sizes;
	vector<size_t>capacities;
	size_t el_incr{ 10 };
	size_t incr_count{ 4 * el_incr };

	for (size_t n_elements{}; n_elements < incr_count; n_elements += el_incr)
	{
		vector<int>values(n_elements);
		cout << "\nAppending to a vector with" << n_elements << "initial elements:\n";
		sizes.push_back(values.size());
		size_t space{ value.capacity() };
		capacities.push_back(space);

		size_t count{};
		size_t n_increase{ 10 };
		while (count < n_increase)
		{
			values.push_back(22);
			if (space < values.capacity())
			{
				space = values.capacity();
				capacities.push_back(space);
				sizes.push_back(values.size());
				++count;
			}
			
		}
		cout << "size/capacity";
		for (size_t i{}; i < sizes.size(); i++)
		{
			cout << sizes.at(i) << "/" << capacities.at(i) << " ";


		}
		cout << endl;
		sizes.clear();
		capacities.clear();

	}




	getchar();
	return 0;

}