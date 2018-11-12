#include<iostream>
#include<string>
#include<deque>
#include<list>

using namespace std;

int main()
{
	deque<string> words;
	string word;
	while (!(cin >> word).eof())
	{ 
		words.push_back(word);
	}
	list<string> words2;
	//words2.assign(begin(words), end(words));
	//cout << words2.front();
	for (int i = 1; i <= words.size(); i++)
	{
		string wordd = words.front();
		//cout << words.front();
		words.push_back(wordd);
		words.pop_front();
		words2.push_back(wordd);

	}
//	cout << words2.front();
	for (auto &k : words2)
		cout << k << endl;



	getchar();
	return 0;

}