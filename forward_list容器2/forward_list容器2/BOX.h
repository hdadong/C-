#pragma once
#ifndef BOX_H
#define BOX_H
#include<iostream>
#include<utility>
using namespace std;

class Box
{
private:
	size_t length{};
	size_t width{};
	size_t height{};
public:
	explicit Box(size_t l = 1, size_t w = 1, size_t h = 1) :length{ l }, width{ w }, height{ h }{};
	double volume()const { return length * width*height; };
	bool operator<(const Box&box) { return volume() < box.volume(); };
	bool operator==(const Box&box) { return length == box.length&&width == box.width&&height == box.height; };
	friend istream&operator >>(istream &in, Box &box);
	friend ostream&operator <<(ostream &out, const Box&box);


};

inline istream& operator >>(istream& in, Box&box)
{
	cout << "Enter box length,width,&height seperated by spaces -Ctrl+z to end:";
	size_t value;
	in >> value;
	if (in.eof())return in;

	box.length = value;
	in >> value;
	box.width = value;
	in >> value;
	box.height = value;
	return in;
}

inline ostream& operator<<(ostream &out, const Box&box)
{
	out << "Box(" << box.length << "," << box.width << "," << box.height << ")";
	return out;
}


#endif
