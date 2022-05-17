#include "Table.h"
#include "Guest.h"
#include "Order.h"
#include "Drink.h"
#include "Food.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define NUMBER_OF_TABLES 10 // A vendeglato helyisegunk limitalt helyel dolgozik. Hogy ne legyenek "magic number"-ek

using namespace std;

void help() {
	cout << "commands: menu exit " << endl;
}

void UserOrder(vector<Drink> pDrinkmenu, vector<Food> pFoodmenu, vector<Table> pTableList) {
	cout << "Select Table: ";
	for (int i = 0; i < pTableList.size(); i++) {
		cout << "[" << pTableList[i].getTableId() << "]" << endl;
	}
	
	int gId;

	cout << "Input Guest's ID: " << endl;
	cin >> gId;
	cout << "Specify your order, type | f | for food or | d | for drink" << endl;
	string UserInput;
	cin >> UserInput;
	if (UserInput == "f") {
		cout << "Select item: ";
		int id;
		cin >> id;
		if (id > pFoodmenu.size() || id < pFoodmenu.size()) {
			cerr << "Sadly this isn't on the menu";
		}
		else {

		}

	}
}

void UserGetMenu(vector<Drink> pDrinkmenu,vector<Food> pFoodmenu) {
	cout << "-----------------------------------------------------------------" << endl;
	cout << "------------------------Drinks-----------------------------------" << endl;
	Drink::getMenu(pDrinkmenu);
	cout << "------------------------Foods------------------------------------" << endl;
	Food::getMenu(pFoodmenu);
	cout << "-----------------------------------------------------------------" << endl;
}


int main() {
	vector<Table> TableList;
	vector<Drink> Drinkmenu;
	vector<Food> Foodmenu;
	Table::loadTables(TableList);
	Drink::loadMenu(Drinkmenu);
	Food::loadMenu(Foodmenu);
	help();
	string UserInput;

	


	Guest alany;

	alany.addOrder(&Drinkmenu.at(5-1));
	alany.addOrder(&Drinkmenu.at(5 - 1));
	alany.addOrder(&Foodmenu.at(8 - 1));

	alany.print();


	while (true) {
		cin >> UserInput;
		if (UserInput == "menu") {
			UserGetMenu(Drinkmenu,Foodmenu);
		}
		if (UserInput == "order") {
			UserOrder(Drinkmenu, Foodmenu,TableList);
		}




		if (UserInput == "help") {
			help();
		}
		if (UserInput == "exit") {
			return 0;
		}
	}



	return 0;
}