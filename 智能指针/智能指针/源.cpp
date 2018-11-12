#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	auto comp = [](const shared_ptr<string>&wp1, const shared_ptr<string>&wp2) {return *wp1 < *wp2; };
	priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)>words1{ comp };//decltype推断类型，但并不执行

	vector<shared_ptr<string>> init{ make_shared<string>("one"),
		make_shared<string>("two"),
		make_shared<string>("three"),
		make_shared<string>("four") };

	priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)>words(comp, init);

	priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)>words2{ comp };
	words2.emplace(new string{ "two" });
	words2.emplace(new string("three"));

	make_heap(begin(init), end(init)[](const shared_ptr<string>&wp1, const shared_ptr<string>&wp2) {return *wp1 < *wp2; });
}