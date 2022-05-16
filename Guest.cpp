#include "Guest.h"

using namespace std;
Guest::Guest(const Guest& other)
{
	id = other.id;
	total = other.total;
	paidStatus = other.paidStatus;
	orderCount = other.orderCount;
}

Guest::~Guest()
{
	delete[] orders;
}

int Guest::getId() const
{
	return id;
}

void Guest::setTotal(int pPrice)
{
	total += pPrice;
}

int Guest::getTotal() const
{
	return total;
}

void Guest::setPaidStatus()
{
	paidStatus = true;
}

bool Guest::getPaidStatus() const
{
	return paidStatus;
}

void Guest::addOrder(Order* pOrder)
{
	orders[orderCount] = pOrder;
	setTotal(pOrder->getPrice());
	orderCount++;
}

void Guest::removeOrders()
{
	for (int i = orderCount; i >= 0; --i) {
		delete[] orders[i];
	}
}

void Guest::print() const
{
	cout << "Guest's ID: " << id << endl;
	cout << "Check Total currently: " << total << endl;
	cout << "Status: ";
	if (paidStatus) {
		cout << "Paid" << endl;
	}
	else {
		cout << "Pending Payment" << endl;
	}
	for (int i = 0; i < orderCount; i++) {
		orders[i]->print();
	}
}
