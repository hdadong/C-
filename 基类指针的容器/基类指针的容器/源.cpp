#include<iostream>
//#include<utility>
#include<memory>
#include<vector>

using namespace std;
class Box
{
protected:
	size_t length{};
	size_t width{};
	size_t height{};

public:
	explicit Box(size_t l = 1, size_t w = 1, size_t h = 1) :length(l), width(w), height(h) {};
	virtual ~Box() = default;
	virtual double volume()const;
	bool operator<(const Box&box)const;
	bool operator==(const Box&box)const;

	virtual istream&read(istream&in);
	virtual ostream&write(ostream&out)const;

};

inline double Box::volume()const { return length * width*height; };
inline bool Box::operator<(const Box&box) const{
	return volume() < box.volume();
};

inline bool Box::operator==(const Box&box)const
{
	return length == box.length&&width == box.width&&height == box.height;
};

inline istream&operator>>(istream&in, Box&box)
{
	return box.read(in);
};

inline ostream&operator<<(ostream&out, Box&box)
{
	return box.write(out);
};

istream&Box::read(istream&in)
{
	size_t value{};
	if ((in >> value).eof())
		return in;
	length = value;
	in >> width >> height;
	return in;

}

ostream&Box::write(ostream&out)const
{
	out << typeid(*this).name() << "(" << length << "," << width << "," << height << ")";
	return out;
}


class Carton :public Box
{
public:
	explicit Carton(size_t l = 1, size_t w = 1, size_t h = 1) :Box{ l,w,h } {};
	double volume()const override { return 0.85*Box::volume(); };
};
int main()
{
	vector<unique_ptr<Box>>boxes;
	boxes.push_back(make_unique<Box>(1, 2, 3));
	boxes.push_back(make_unique<Carton>(1, 2, 3));
	boxes.push_back(make_unique<Carton>(4, 5, 6));
	boxes.push_back(make_unique<Box>(4, 5, 6));
	for (auto&&ptr : boxes)
		cout << *ptr << "volume is" << ptr->volume() << endl;


	getchar();
	return 0;

}