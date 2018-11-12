#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<functional>
using namespace std;

template<typename T>
void list_pq(priority_queue<T,vector<T>,greater<T>>pq, size_t count = 5)
{
	size_t n{ count };
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
		if (--n)continue;//当N=0时执行下面的语句
		cout << endl;
		n = count;
	}
	cout << endl;
}
int main()
{
	string wrd[]{ "one","two","four" };
	priority_queue<string, vector<string>,greater<string>> words{ begin(wrd),end(wrd) };

	
	priority_queue<string>words2{ begin(wrd),end(wrd) };

	priority_queue<string, deque<string>>words3{ begin(wrd),end(wrd) };

	vector<int>values{ 21,22,12,3,24,54,56 };//直接用vector或者queue初始化 不能直接用string初始化
	priority_queue<int>words4{ less<int>(),values};

	priority_queue<int, vector<int>, greater<int>>numbers{ greater<int>(),values };

	cout << "输入单词：" << endl;
	string word;
	while (true)
	{
		if ((cin >> word).eof())
			break;
		words.push(word);
	}
	/*
	//把words复制给words_copy再打印
	priority_queue<string,vector<string>,greater<string>>words_copy{words  };
	while (!words_copy.empty())
	{
		cout << words_copy.top() << " ";
		words_copy.pop();

	}
	cout << endl;
	*/

	words.emplace("ggg");


	list_pq(words);



	getchar();
	return 0;
}