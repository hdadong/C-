#include<iostream>
using namespace std;
#include<iterator>
#include<functional>
#include<iterator>
#include<algorithm>
/*
int main() {
	int data[]{ 1,2,3,4,5 };
	auto c = begin(data);
	for (; c != end(data); c++)
	{
		cout << *c << endl;
	}
	getchar();
	return 0;
}*/

int main()
{
	char array[]{ 'a','A','C','t' ,'e'};


	function<char(char )> op
	{ [](char array) 
	{
		if (array >= 97 && array <= 122)
		{
			array = '*';
		}
		return array;
	} };
	int size = sizeof(array);
	transform(begin(array), end(array), ostream_iterator<char>(cout, " "),op);
//	cout << sizeof(array);
	getchar();
	return 0;
}

