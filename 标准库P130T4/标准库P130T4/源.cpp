#include<memory>
#include<Vector>
#include<string>
#include<iostream>
#include<deque>
#include<list>
using namespace std;

int main()
{
	deque<shared_ptr<string>>words;
	string word;
	while (!(cin >> word).eof())
	{
		words.push_back(make_shared<string>(word));
	}

	int size = words.size();
	list<string>words2;
	for (int i = 1; i <= size; i++)
	{
		words.push_back(words.front());
		words2.push_back(*words.front());
		words.pop_front();
	}

	words2.sort();
	for (auto &k : words2)
	{
		cout << k;
	}
	
	getchar();
	return 0;

}