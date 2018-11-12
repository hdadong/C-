#include<iostream>
#include<numeric>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<shared_ptr<string>>words{ make_shared<string>("one"),make_shared<string>("two"),make_shared<string>("three"),make_shared<string>("four") };
	auto str = accumulate(begin(words), end(words), string{ "" }, [](const string&s, const shared_ptr<string>&pw)->string {return s + *pw + ""; });

}