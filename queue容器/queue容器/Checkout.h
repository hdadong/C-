#pragma once
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include<queue>
#include"Customer.h"
using namespace std;
class Checkout
{
private:
	queue<Customer>customers;
	 int relax=0;
public:
	void add(const Customer&customer) { customers.push(customer); };
	size_t qlength()const { return customers.size(); };
	void time_increment()
	{
		if (!customers.empty()&&relax==0)
		{
			if (customers.front().time_decrement().done())
				customers.pop();
		}
	};
	Customer turn_line()
	{
		Customer p = customers.front();
		customers.pop();
		return p;
	}
	void let_him_relax() { relax = 1; };
	bool operator<(const Checkout& other)const { return qlength() < other.qlength(); };
	bool operator>(const Checkout& other)const { return qlength() > other.qlength(); };
	bool if_relax() { return relax == 1; };
};
#endif
