#include<iostream>
#include<queue>
#include<string>
#include<memory>

using namespace std;

int main()
{
	//vector<unique_ptr<string>>init{ make_unique<string>("abc") };
	priority_queue<unique_ptr<string>, vector<unique_ptr<string>>, less<unique_ptr<string>>  >words{ less<unique_ptr<string>>() };
	string word;
	
	
	
	
					 
	while (!(cin >> word).eof())
	{
		words.push(make_unique<string>(word));


	}
	
	while (!words.empty())
	{
		cout <<*words.top();
		words.pop();
	}
	

	getchar();
	return 0;
}