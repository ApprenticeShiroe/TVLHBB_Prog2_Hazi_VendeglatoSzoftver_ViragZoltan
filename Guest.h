#pragma once
#include "Order.h"
#include <iostream>


static int nextid = 0;

class Guest
{
private:
	int id;
	int total;
	bool paidStatus;
	Order* orders;
public:
	Guest() :id(++nextid), total(0), paidStatus(false), orders(nullptr) {};
	Guest(const Guest& other);
	~Guest();

	int getId()const;

	void setTotal(int pPrice);
	int getTotal()const;

	void setPaidStatus();
	bool getPaidStatus()const;

	void addOrder(const Order& pOrder);
	void removeOrder(); //maybe

	void print()const;

};

