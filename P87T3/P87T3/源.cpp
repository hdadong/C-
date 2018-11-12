#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<algorithm>
#include<functional>
#include<cstring>
#include<list>
#include<deque>
using namespace std;
template<typename Iter>
void Print(Iter A, Iter C)
{
	int count = 0;
	while (A != C)
	{
		if (count != 0)cout << *A << " ";
	/*	if (count != 0 && (*A)[0] == (*(A - 1))[0])
		{
			cout << *A << " ";
		}
		else if (count != 0 && (*A) != (*(A - 1))[0])
		{
			cout << endl;
			cout << *A << " ";
		}*/
		count++;
		++A;
	}
}


int main()
{
	list<string>data;
	string Data;
	while (getline(cin, Data, '\n'))
		data.push_front(Data);
//	data.sort();
	//Print(begin(data),end(data));
	deque<string>data2;
	for (auto itt = begin(data); itt != end(data); itt++)
	{
		data2.push_back(*itt);
	}
	sort(begin(data2), end(data2));
	copy(begin(data2), end(data2), ostream_iterator<string>{cout, " "});




	getchar();
	return 0;


}