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



	//����һ��ԭ��ָ��
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
			iter=words2.erase(iter);//����һ��ָ��ɾ��Ԫ�غ��һ��Ԫ��
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
	cout << "���뵥��:" << endl;
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