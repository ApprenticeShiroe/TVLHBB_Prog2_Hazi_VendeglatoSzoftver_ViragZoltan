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

void help() {
	cout << "commands: menu exit " << endl;
}

void UserOrder() {
	cout << "Specify your order, type | f | for food or | d | for drink" << endl;
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

	vector<Drink> Drinkmenu;
	vector<Food> Foodmenu;

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
			UserOrder();
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