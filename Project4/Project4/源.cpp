#include<iostream>
#include<string>

using namespace std;

int main()
{
	string th{ "1x523" };
	size_t c{};
	cout << stod(th.substr(2), &c) << c;
	getchar();
	return 0;
}