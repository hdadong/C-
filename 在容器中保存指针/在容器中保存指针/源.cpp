#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	/*vector<unique_ptr<string>>words;
	words.push_back(make_unique<string>("one"));
	words.push_back(make_unique<string>("two"));

	unique_ptr<string>pname{ new string {"one"} };
	words.push_back(pname);

	auto pstr = make_unique<string>(6, '*');
	words.push_back(pstr);
	*/



	//储存一个原声指针
	vector<string*>words2;
	string word;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words2.push_back(new string{ word });
	}

	for (auto&w : words2)
	{
		cout << *w << " ";
	}
	cout << endl;

	for (auto iter = begin(words2); iter != end(words2);)
	{
		if (**iter == "one")
		{
			delete *iter;
			iter=words2.erase(iter);//返回一个指向被删除元素后的一个元素
		}
		else {
			iter++;
		}
}

	for (auto&w : words2)
	{
		cout << *w << " ";
	}
	cout << endl;


	vector<shared_ptr<string>>words3;
	cout << "输入单词:" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear;
				break;
		}
		words3.push_back(make_shared<string>(word));
	}






	getchar();
	return 0;
}