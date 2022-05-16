#include "Drink.h"

Drink::Drink(const Drink& other)
{
	name = other.name;
	isAlcoholic = other.isAlcoholic;
}

string Drink::getName() const
{
	return name;
}

string Drink::getUnit() const
{
	return unit;
}

void Drink::print() const
{
	cout << " | " << name << " | " << price << " Ft" << " | " << quantity << unit;
	if (isAlcoholic == true) {
		cout << " | Alkoholos |" << endl;
	}
	else {
		cout << " | Alkoholmentes |" << endl;
	}
}
