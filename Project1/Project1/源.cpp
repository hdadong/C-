#include<iostream>
using namespace std;
char pd(int a, int b)
{
	if (a > b)
	{
		return '>' ;

	}
	if (a < b)
	{
		return'<';
	}
	else
	{
		return '=';
	}
}
int main()
{
	int a = 32, b = 29;
	char c = pd(a, b);
	cout << c;
	return 0;
}
