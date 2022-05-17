#include "Food.h"

Food::Food(const Food& other)
{
	name = other.name;
	isVegan = other.isVegan;
	price = other.price;
	quantity = other.quantity;
}

void Food::loadMenu(vector<Food>& pFoodmenu)
{
	ifstream menuFile;
	menuFile.open("foodmenu.txt", ifstream::in);
	if (!menuFile.is_open()) {
		cerr << "Error while trying to open file!";
	}
	else {
		cout << "Reading from foodmenu.txt." << endl;
		int tmpPrice = 0;
		double tmpQuant = 0.0;
		string tmpName;
		int tmpState;
		while (!menuFile.eof()) {
			menuFile >> tmpName >> tmpPrice >> tmpQuant >> tmpState;
			if (tmpState == 1) {
				pFoodmenu.push_back(Food(tmpPrice, tmpQuant, tmpName, true));
			}
			else {
				pFoodmenu.push_back(Food(tmpPrice, tmpQuant, tmpName, false));
			}
		}
	}
	menuFile.close();
}

void Food::getMenu(vector<Food>& pFoodmenu)
{
	for (int i = 0; i < pFoodmenu.size(); i++) {
		cout << (i + 1);
		pFoodmenu[i].print();
	}
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
		cout << " | not Vegan |" << endl;
	}
}
