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
	//virtual ~Order();

	void setPrice(int pPrice);
	int getPrice()const;

	void setQuantity(double pQuantity);
	double getQuantity()const;

	virtual void print()const;
};

