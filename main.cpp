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
	vector<Drink> Drinkmenu;
	//vector<Food> FoodMenu;

	Drink::loadMenu(Drinkmenu);
	Drink::getMenu(Drinkmenu);

	Guest alany;

	alany.addOrder(new Drink(Drinkmenu.at(5-1)));
	alany.print();
	alany.removeOrders();


	/*
	ifstream menuFile;
	menuFile.open("drinkmenu.txt", ifstream::in);
	if (!menuFile.is_open()) {
		cerr << "Error while trying to open file!";
	}
	else {
		int tmpPrice = 0;
		double tmpQuant = 0.0;
		string tmpName;
		int tmpState;
		while (!menuFile.eof()) {
			menuFile >> tmpName >> tmpPrice >> tmpQuant >> tmpState;
			if (tmpState == 1) {
				Drinkmenu.push_back(Drink(tmpPrice, tmpQuant, tmpName, true));
			}
			else {
				Drinkmenu.push_back(Drink(tmpPrice, tmpQuant, tmpName, false));
			}
		}
	}
	menuFile.close();

	for (int i = 0; i < Drinkmenu.size(); i++) {
		Drinkmenu[i].print();
	}




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