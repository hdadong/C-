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

	//����һ�����е�һ�γ�ʼ��
	list<string>words2{ ++cbegin(words),--cend(words) };

	auto iter = begin(words2);
	advance(iter, 9);//����iter
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
	//words2.emplace_back(move(words));//��words��ֵ���ô��룬names��Ϊ��


	words2.remove("ha");
	for (const auto&k : words2)
	{
		cout << k << " ";
	}
	cout << endl;
	words2.remove_if([](string th) {return th == "log"; });//����һ�����ԣ�����true������Ԫ�ض��ᱻɾ��

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
	//words2.unique();//�����Ƴ��ظ�Ԫ�أ�ֻ����һ��
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

	//���Ѿ��ź����������
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


	//�������޲���merge��seven����six֮ǰ
	my_words.merge(your_words,com_ptr);
	for (const auto&k : my_words)
	{
		cout << k << " ";
	}
	cout << endl;


	list<string>my_words2{ "tree","six","eight" };
	list<string> your_words2{ "seven","four","nine" };

	my_words2.splice(++begin(my_words2), your_words2, ++begin(your_words2));
	//��yourwords�ĵڶ���Ԫ�ز��뵽myword�ĵڶ�������
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

		//��My_words�ĵڶ���Ԫ�ص�ĩβ��Ԫ�ز��뵽yourword�ĵڶ���Ԫ��
		your_words2.splice(++begin(your_words2), my_words2, ++begin(my_words2), end(my_words2));
		for (auto &k : your_words2)
		{
			cout << k << " ";
		}
		cout << endl;

		my_words2.splice(begin(my_words2), your_words2);//��youRwordȫ����mywords
	//	my_words2.sort();
		for (auto &k : my_words2)
		{
			cout << k << " ";
		}
		cout << endl;
		








	getchar();
	return 0;
}