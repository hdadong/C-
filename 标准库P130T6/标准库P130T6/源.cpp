#include<vector>
#include<memory>
#include<string>
#include<iostream>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	vector<shared_ptr<string>>words;
	string word;
	while (!(cin >> word).eof())
	{
		words.push_back(make_shared<string>(word));

	}

	auto comp = [](shared_ptr<string> r1, shared_ptr<string> r2) {return *r1 > *r2; };
	sort(begin(words), end(words), comp);
	

	for (auto &l : words)
	{
		cout << *l << endl;
	}


	getchar();
	return 0;
}