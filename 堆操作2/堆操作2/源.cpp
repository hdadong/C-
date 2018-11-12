#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<iomanip>
using namespace std;

void show(const deque<string>&words, size_t count = 5)
{
	if (words.empty()) return;//��֤������Ԫ��
	//��Ѱ����ַ���
	auto max_len = max_element(begin(words), end(words), [](const string&s1, const string&s2) {return s1.size() < s2.size(); })->size();
	//max_element��Ҫ����С�ڶ����Ǵ�������
	//����ַ���
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
	cout << "�����뵥�ʣ�" << endl;
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
	cout << "���ɶѺ󣬵������б���������:" << endl;
	show(words);

	cout << "��������" << words.size() << "�����ʣ����������ĵ���" << endl;
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
	cout << "���ڵ������б��������ǣ�" << endl;
	show(words);


	getchar();
	return 0;
}