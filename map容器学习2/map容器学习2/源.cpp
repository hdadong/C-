#include"NAME.h"
//#include<utility>
#include<cctype>

int main()
{/*
	map<Name, size_t>people{ {{"ANN","aaa"},125 }, { { "aad","ccd" }, 155 } };

	cout << "The initial contents of the map is:" << endl;
	list_entries(people);

	char answer{ 'Y' };
	cout << "Enter a Name and age entry" << endl;
	while (toupper(answer) == 'Y')
	{
		pair<const Name,size_t> entry{ get_entry() };
		auto pr = people.insert(entry);
		if (!pr.second)//插入失败
		{
			cout << "Key\"" << pr.first->first << "\"already present.do you want to update the age(Y or N)?";
			cin >> answer;
			if (toupper(answer) == 'Y')
				pr.first->second = entry.second;

		}
		cout << "do you want to enter another entry (Y or N)?";
		cin >> answer;

	}
	cout << "the map now contains the following entries:" << endl;
	list_entries(people);

	*/
	map<Name, size_t>people;
	int count = people.size();
	auto pr = people.emplace(Name{ "Dan","Druff" }, 77);	//返回pair类型，second为bool
	auto iter = people.emplace_hint(pr.first, Name{ "Cal","cutta" }, 62);
	if (count < people.size()) cout<< "Success!"<<endl;



	Name key;
	try
	{
		key = Name{ "Dan","Druff" };
		auto value = people.at(key);
		cout << key << "is age" << value << endl;
		key = Name{ "Don","Druff" };
		value = people.at(key);
		cout << key << "is age" << value << endl;
	}
	catch (const std::out_of_range&e)
	{
		std::cerr << e.what() << '\n' << key << "was not found." << std::endl;


	}


	getchar();
	getchar();
	return 0;
}