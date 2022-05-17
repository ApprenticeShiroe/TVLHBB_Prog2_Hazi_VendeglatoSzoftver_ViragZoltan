#pragma once
#include "Order.h"
#include <iostream>
#include <vector>


static int nextid = 0;
using namespace std;
class Guest
{
private:
	int id;
	int total;
	bool paidStatus;
	int orderCount;
	Order* orders[30];
public:
	Guest() :id(++nextid), total(0), paidStatus(false), orders(), orderCount(0) {};
	Guest(const Guest& other);

	int getId()const;

	void setTotal(int pPrice);
	int getTotal()const;

	void setPaidStatus();
	bool getPaidStatus()const;



	void addOrder(Order* pOrder);

	void print()const;

	/*Order* operator[](int index)const {
		if (!orderCount || index >= orderCount || index < 0) {
			return NULL;
		}
		return orders[index];
	}*/
};

