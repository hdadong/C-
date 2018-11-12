#pragma once
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include<queue>
#include<memory>
#include"Customer.h"
using namespace std;
class Checkout
{
private:
	queue<unique_ptr<Customer>>customers;
public:
	//unique_ptr不能被复制，所以参数是右值引用，参数会被移动到容器中。
	void add(unique_ptr<Customer>&&customer) { customers.push(move(customer)); };
	size_t qlength() const { return customers.size(); };

	void time_increment()
	{
		if (customers.front()->time_decrement().done())
		{
			
			customers.pop();
			
		}
	};

	bool if_customer() { return customers.size(); };
	bool operator<(const Checkout&other)const { return qlength() < other.qlength(); }
	bool operator>(const Checkout&other)const { return qlength() < other.qlength(); }


};
#endif