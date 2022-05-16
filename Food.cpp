#include "Food.h"

Food::Food(const Food& other)
{
	name = other.name;
	isVegan = other.isVegan;
	price = other.price;
	quantity = other.quantity;
}

string Food::getName() const
{
	return name;
}

string Food::getUnit() const
{
	return unit;
}

void Food::print() const
{
	cout << " | " << name << " | " << price << " Ft" << " | " << quantity << unit;
	if (isVegan == true) {
		cout << " | Vegan |" << endl;
	}
	else {
		cout << " | Nem vegan |" << endl;
	}
}
