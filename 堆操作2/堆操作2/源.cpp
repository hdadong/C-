#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<iomanip>
using namespace std;

void show(const deque<string>&words, size_t count = 5)
{
	if (words.empty()) return;//保证队列有元素
	//搜寻最长的字符串
	auto max_len = max_element(begin(words), end(words), [](const string&s1, const string&s2) {return s1.size() < s2.size(); })->size();
	//max_element需要定义小于而不是大于运算
	//输出字符串
	size_t n{ count };
	for (const auto&word : words)
	{
		cout << setw(max_len + 1) << word << " ";
		if (--n)continue;
		cout << endl;
		n = count;
	}
	cout << endl;
}


int main()
{
	deque<string>words;
	string word;
	cout << "请输入单词：" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push_back(word);
	}
	cout << "the words in the list are:" << endl;
	show(words);

	make_heap(begin(words), end(words));
	cout << "生成堆后，单词在列表中排列是:" << endl;
	show(words);

	cout << "你输入了" << words.size() << "个单词，请输入更多的单词" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push_back(word);
		push_heap(begin(words), end(words));
	}
	cout << "现在单词在列表中排序是：" << endl;
	show(words);


	getchar();
	return 0;
}