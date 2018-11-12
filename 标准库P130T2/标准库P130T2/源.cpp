#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<char>words;
	char word;
	while (!(cin>>word).eof())
	{
		words.push(word);
	}
	stack<char>words2;
	words2 = words;

	stack<char>words3;
	for (int i = 1; i <= words2.size(); i++)
	{
		words3.push(words.top());
		cout << words.top() ;
		words.pop();
	}
	if (words2 == words3)
	{
		cout << "是回文" << endl;
	}
	else
	{
		cout << "不是回文" << endl;
	}

	getchar();
	return 0;


}