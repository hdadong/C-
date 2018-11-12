#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

class my_greater
{
public:
	bool operator ()(string r1, string r2)
	{
		if (r1[0] == r2[0])
		{
			return(r1.length() > r2.length());
		}
		else
			return r1 < r2;
	}
};
int main()
{
	list<string>words(15, "ha");

	//用另一个序列的一段初始化
	list<string>words2{ ++cbegin(words),--cend(words) };

	auto iter = begin(words2);
	advance(iter, 9);//自增iter
	words2.insert(iter, 3, "log");
	auto start = begin(words2);
	auto finish =end(words2);
	while (start != finish)
	{
		cout << *start << " ";
		start++;

	}
	cout << endl;
	words2.emplace(begin(words2), "Haman");
	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;
	//words2.emplace_back(move(words));//将words右值引用传入，names变为空


	words2.remove("ha");
	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;
	words2.remove_if([](string th) {return th == "log"; });//传入一个断言，返回true的所有元素都会被删除

	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;

	words2.insert(begin(words2),2, "gg");
	words2.insert(begin(words2), 1, "gggs");
	words2.push_back("gts");
	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;
	//words2.unique([](string r1, string r2) {return sizeof(r1) == sizeof(r2); });
	//words2.unique();//连续移除重复元素，只留下一个
	words2.sort(my_greater());
	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;
	string th = "gggs";
	string ch = "haman";
	if (th >ch)cout << "a";
	//words2.unique([](string r1, string r2) {return r1[0] == r2[0]; });

	//把已经排好序的链表结合
	list<int> my_value{ 2,4,6,14 };
	list<int> your_value{ -2,1,7,10 };
	my_value.merge(your_value);
	your_value.empty();
	for (const auto&k : my_value)
	{
		cout << k << " ";
	}
	cout << endl;


	list<string> my_words{ "three","six","eight" };
	list<string> your_words{ "seven","four","nine" };

	auto com_ptr = [](const string &r1, const string &r2) {return r1[0] < r2[0]; };
	my_words.sort(com_ptr);
	your_words.sort(com_ptr);


	//若调用无参数merge则seven会在six之前
	my_words.merge(your_words,com_ptr);
	for (const auto&k : my_words)
	{
		cout << k << " ";
	}
	cout << endl;


	list<string>my_words2{ "tree","six","eight" };
	list<string> your_words2{ "seven","four","nine" };

	my_words2.splice(++begin(my_words2), your_words2, ++begin(your_words2));
	//把yourwords的第二个元素插入到myword的第二个参数
	auto start2 = begin(my_words2);
	auto finish2 = end(my_words2);
		for (auto itt = start2; itt != finish2; itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;

		for (auto &k : your_words2)
		{
			cout << k << " ";
		}
		cout << endl;

		//把My_words的第二个元素到末尾的元素插入到yourword的第二个元素
		your_words2.splice(++begin(your_words2), my_words2, ++begin(my_words2), end(my_words2));
		for (auto &k : your_words2)
		{
			cout << k << " ";
		}
		cout << endl;

		my_words2.splice(begin(my_words2), your_words2);//把youRword全插入mywords
	//	my_words2.sort();
		for (auto &k : my_words2)
		{
			cout << k << " ";
		}
		cout << endl;
		








	getchar();
	return 0;
}