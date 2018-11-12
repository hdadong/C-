#include<functional>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	priority_queue<string, vector<string>, less<string>> words{ less<string>() };
	string word;
	while (!(cin >> word).eof())
	{
		words.push(word);
	}

	int t = words.size();
	string word2;
	for (int i = 1; i <= t; i++)
	{
		cout << words.top() << endl;;
		words.pop();
	}

	getchar();
	return 0;
}