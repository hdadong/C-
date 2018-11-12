#include<map>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	map<string, size_t>people{ {"app",25},{"bill",46},{"javc",32} };
	map<string, size_t>people2{ make_pair("Ann",25),make_pair("Bill",46),make_pair("add",32) };
	map<string, size_t>people3{ people };
	map<string, size_t>people4{ begin(people),end(people) };
	auto pr = make_pair("app", 22);
	auto ret_pr = people.insert(pr);//����ʧ�ܷ���map�е�Ԫ��
	cout << ret_pr.first->first << " " << ret_pr.first->second << " " << boolalpha << ret_pr.second << endl;
	ret_pr = people.insert(pair<const string, size_t>{"Bill", 48});//��ֵ���ð汾
	ret_pr = people.insert(make_pair("Cim", 48));
	people.insert(make_pair("Dim", 48));
	people.insert(ret_pr.first, make_pair("Ean", 38));//ʹ��������뾡���ܿ���ret_pr.first
	if (!people.count("Tan"))
		people.insert(ret_pr.first, make_pair("Tan", 32));
	/*if (!ret_pr.second)
	{
		ret_pr.first->second = 48;
	}*/
	//cout << pr.second;

	map<string, size_t>crowd;
	auto iter = begin(people);
	advance(iter, 4);
	crowd.insert(begin(people), iter);
	for (const auto&p : crowd)
	{
		cout << setw(10) << left << p.first << " " << p.second << endl;//���Ĭ���Ե�һ��Ԫ����������
	}



	getchar();
	return 0;
}