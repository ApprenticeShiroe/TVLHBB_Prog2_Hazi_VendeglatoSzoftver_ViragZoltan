#include "Table.h"
#include "Guest.h"
#include "Order.h"
#include "Drink.h"
#include "Food.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int main() {
	
	Drink::loadMenu();
	Drink::getMenu();
	
	
	
	
	
	
	/*
	vector<Drink> VectorDrinks;

	ifstream drinkmenu;
	int tmpPrice;
	double tmpQuant;
	string tmpName;
	int tmpState;
	
	drinkmenu.open("drinkmenu.txt", ifstream::in);
	if (!drinkmenu.is_open()) {
		cout << "error while opening the file";
	}
	else {
		cout << "reading from the file contetns" << endl;
		while (!drinkmenu.eof()) {
			drinkmenu >> tmpName >> tmpPrice >> tmpQuant >> tmpState;
			if (tmpState == 1) {
				VectorDrinks.push_back(Drink(tmpPrice, tmpQuant, tmpName, true));
			}
			else {
				VectorDrinks.push_back(Drink(tmpPrice, tmpQuant, tmpName, false));
			}
		}

	}

	//cout << tmpPrice << " " << tmpQuant << " " << tmpName << " " << tmpState << endl;


	drinkmenu.close();

	for (int i = 0; i < VectorDrinks.size(); i++) {
		VectorDrinks[i].print();
	}


	/*

	Guest alany2;
	alany2.print();
	Drink a(*Drinks[2]);
	alany2.addOrder(new Drink(a));


	alany2.print();

	alany2.removeOrders();

	*/

	return 0;
}