#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<algorithm>
#include<functional>
#include<cstring>
#include<list>
using namespace std;
template<typename Iter>
void Print(Iter A,Iter C)
{
	int count = 0;
	while (A != C)
	{
		if (count == 0)cout << *A << " ";
		if (count != 0 && (*A)[0] == (*(A - 1))[0])
		{
			cout << *A << " ";
		}
		else if (count != 0 && (*A)[0] != (*(A - 1))[0])
		{
			cout << endl;
			cout << *A << " ";
		}
		count++;
		++A;
	}
}




int main()
{
	//list<string>data;
	vector<string>data;
	copy(istream_iterator<string>{cin}, istream_iterator<string>{}, back_inserter(data));
	sort(begin(data),end(data));
	Print(begin(data), end(data));




	getchar();
	return 0;


}