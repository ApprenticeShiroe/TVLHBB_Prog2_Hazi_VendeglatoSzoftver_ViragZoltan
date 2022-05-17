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
	int orderCount;
	Order* orders[];
public:
	Guest() :id(++nextid), total(0), paidStatus(false), orders(),orderCount(0) {};
	Guest(const Guest& other);
	~Guest();

	int getId()const;

	void setTotal(int pPrice);
	int getTotal()const;

	void setPaidStatus();
	bool getPaidStatus()const;

	void addOrder(Order* pOrder);

	void print()const;

	Order* operator[](int index)const {
		if (!orderCount || index >= orderCount || index < 0) {
			return NULL;
		}
		return orders[index];
	}
};

