#pragma once
#include <iostream>



class Order
{
protected:
	int price;
	double quantity;
public:
	Order() :price(0), quantity(0.0) {};
	Order(int pPrice, double pQuantity) :price(pPrice), quantity(pQuantity) {};
	Order(const Order& other);

	void setPrice(int pPrice);
	int getPrice()const;

	void setQuantity(double pQuantity);
	double getQuantity()const;

	virtual void print()const;

};

