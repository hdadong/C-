#include<array>
#include<iostream>
using namespace std;
template<typename Iter>
void Print(Iter A, Iter B)
{
	int count = 0;
	while (A != B)
	{
		if (count % 8 == 0)
			cout << endl;
		cout << *A<<" ";
		count++;
		++A;
	}
}

int main()
{
	array<long long int, 50> p{};
	auto sb=[](long long int *p)
	{
		p[0] = 0;
		p[1] = 1;
		for (int i = 2; i <= 49; i++)
		{
			p[i] = p[i - 1] + p[i - 2];
		}
	};
	auto p2 = p.data();
	sb(p2);
	Print(begin(p), end(p));


	getchar();
	return 0;
}
