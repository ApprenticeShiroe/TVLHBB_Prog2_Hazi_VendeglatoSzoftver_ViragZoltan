#include "Drink.h"



Drink::Drink(const Drink& other)
{
	name = other.name;
	isAlcoholic = other.isAlcoholic;
	price = other.price;
	quantity = other.quantity;
}


void Drink::loadMenu(vector<Drink> &pDrinkmenu)
{
	ifstream menuFile;
	menuFile.open("drinkmenu.txt", ifstream::in);
	if (!menuFile.is_open()) {
		cerr << "Error while trying to open file!";
	}
	else {
		cout << "Reading from drinkmenu.txt." << endl;
		int tmpPrice = 0;
		double tmpQuant = 0.0;
		string tmpName;
		int tmpState;
		while (!menuFile.eof()) {
			menuFile >> tmpName >> tmpPrice >> tmpQuant >> tmpState;
			if (tmpState == 1) {
				pDrinkmenu.push_back(Drink(tmpPrice, tmpQuant, tmpName, true));
			}
			else {
				pDrinkmenu.push_back(Drink(tmpPrice, tmpQuant, tmpName, false));
			}
		}
	}
	menuFile.close();
}

void Drink::getMenu(vector<Drink> &pDrinkmenu)
{
	for (int i = 0; i < pDrinkmenu.size(); i++) {
		cout << (i + 1);
		pDrinkmenu[i].print();
	}
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
	cout << " | " << name << " | " << price << " Ft" << " | " << quantity << " " << unit;
	if (isAlcoholic == true) {
		cout << " | Alcoholic |" << endl;
	}
	else {
		cout << " | non-Alcoholic |" << endl;
	}
}