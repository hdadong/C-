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
	value.reserve(20);//û��Ԫ��

	vector<unsigned int>prime{ 2u,3u,4u,5u,7u,11u,13u,17u,19u };
	
	vector<double>values2(20);//Ĭ��ֵ��Ϊ0

	vector<long>number(20, 99L);
	//20��Ԫ�ص�ֵ��Ϊ99L


	//��array��Ԫ�ظ��Ƶ�vector��
	array<string, 5> words2{ "one","two","three","four","five" };
	vector<string>words_copy{ begin(words2),end(words2) };
	for (const auto&w : words2)
	{
		cout << w << endl;
	}
	//���ƶ���������array��Ԫ���ƶ���vector��,�ƶ�֮��arrayΪ���ַ�
	vector<string>words_copy2(make_move_iterator(begin(words2)), make_move_iterator(end(words2)));
	for (const auto&w : words2)
	{
		cout << w << endl;
	}


	vector<size_t>primes{ 2,3,4,5,6,7 };
	cout << primes.capacity();
	cout << primes.size();

	primes.push_back(8);
	cout << primes.capacity();//������ԭ����һ��
	cout << primes.size();//���һ

	primes.resize(10, 99);
	for (auto it = rbegin(primes); it != rend(primes); it++)
	{
		cout << *it << endl;
	}


	//��ɾȥ�����Ԫ��
	primes.resize(5);
	for (auto it = rbegin(primes); it != rend(primes); it++)
	{
		cout << *it << endl;
	}


	//���ص�һ�������һ��Ԫ�ص�����
	primes.front() = 99;
	cout << primes[0] << endl;
	primes.back() = 55;
	cout << primes[primes.size() - 1] << endl;

	//����һ��ָ�������ָ��
	auto pdata = primes.data();//����Pdata��*int���͵�ָ��

	cout << pdata[0] << endl;
/*
	vector<string>words3;
	words3.reserve(10);
	cout << "���뵥�ʲ��ÿո�ֿ�������CTRL+Z��������" << endl;
	copy(istream_iterator<string>{cin}, istream_iterator<string>(), back_inserter(words3));
	cout << "��ʼ����";
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
	cout << "��������" << endl;

	copy(begin(words3), end(words3), ostream_iterator<string>{cout, " "});
	cout << endl;

	vector<string>words3_copy{ make_move_iterator(begin(words3)),make_move_iterator(end(words3)) };
	cout << "���ƶ��񵥴ʺ�word_copy������" << endl;

	cout << "����������" << words3.size() << endl;

	if (words3.front().empty())
	{
		cout << "��һ��Ԫ���ǿյ�" << endl;
	}
	cout << "��һ��Ԫ����" << words3.front() << endl;


	*/
	vector<string>words;
	words.push_back(string("abcd"));

	words.emplace_back("abs");//�������������ֱ�����ɣ��������ȵ������ɶ����ٰ�����Ϊ��������
	words.emplace_back("alleged", 2, 3);//������2��ʼ�������ַ�

	auto iter = words.emplace(++begin(words), 5, 'A');//��һ�������ǵ�������ȷ����������λ�ã�����5��A
	//emplace�᷵��һ��ָ�����Ԫ�صĵ�����
	words.emplace(++iter, "$$$$");
	for (const auto&k : words)
	{
		cout << k << " ";

	}
	cout << endl;

	//insert���������ذ汾���ڶ���������ͬ��һ����const T&ֱ�Ӹ��ƶ����ȥ��������һ���汾��T&&��ֵ���ã��ѵڶ��������ƶ���ȥ
	 iter = words.insert(++begin(words), "two");//��������insert��ֵ���õİ汾,two�����ʱ����ᱻ�ƶ����뵽�����ж����Ǹ��ƹ�ȥ
	//emplace����Ч������Ҫ������ʱ����two
	//����������������ڵ�����ָ��Ԫ��֮ǰ���������෴
	 for (const auto&k : words)
	 {
		 cout << k << " ";
	 }
	 cout << endl;




	string more[]{ "five","six","seven" };
	iter = words.insert(--end(words), begin(more), end(more));//���صĵ�����ָ�����ĵ�һ��Ԫ��five
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;



	//��ĩβ����
	iter = words.insert(end(words), "ten");
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;


	//������Ԫ��
	iter = words.insert(cend(words) , 2, "nine");//cend��const������
	for (const auto&k : words)
	{
		cout << k << " " ;
	}
	cout << endl;
	

	cout << "��������Ϊ��" << words.capacity() << endl;
	words.pop_back();
	words.shrink_to_fit();
	cout << "��������Ϊ��" << words.capacity() << endl;
	iter = words.insert(cend(words), 2, "nine");//cend��const������
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;


	iter = words.erase(begin(words)+1);//ɾ���ڶ���Ԫ��
	for (const auto&k : words)
	{
		cout << k << " ";
	}
	cout << endl;

	iter = words.erase(begin(words) + 1, begin(words) + 3);//ɾ���ڶ����͵�����Ԫ��
	for (const auto&k :words)
	{
		cout << k << " ";
	}
	cout << endl;

	auto iter2 = words.insert(begin(words)+1, "nine");
	iter2 = words.insert(begin(words) + 3, "nine");
	iter = words.insert(cend(words), 2, "nine");//cend��const������
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
	//�Ƴ�ͬ����Ԫ��
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