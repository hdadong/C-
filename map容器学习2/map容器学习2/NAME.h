#pragma once
#ifndef NAME_H
#define NAME_H
#include<string>
#include<iostream>
#include<istream>
#include<map>
#include<iomanip>
using namespace std;
class Name
{
private:
	string first{};
	string second{};

public:
	Name(const string&name1, const string&name2) :first(name1), second(name2) {};

	Name() = default;

	bool operator<(const Name&name)const
	{
		return second < name.second || (second == name.second&&first < name.first);
	}

	friend istream&operator>>(istream&in, Name&name);
	friend ostream&operator<<(ostream&out, const Name&box);

};

inline istream&operator>>(istream&in, Name&name)
{
	in >> name.first >> name.second;
	return in;
}

inline ostream&operator<<(ostream&out, const Name&name)
{
	out << name.first + " " + name.second;
	return out;
}

pair<const Name, size_t> get_entry()//一个输入函数
{
	cout << "Enter first and second names followed by the age:";
	Name name{};
	size_t age{};
	cin >> name >> age;
	return make_pair(name,age);
}

void list_entries(const map<Name, size_t>&people)
{
	for (auto&entry : people)
	{
		cout << left << setw(30) << entry.first << right << setw(4) << entry.second << endl;
	}
}


#endif