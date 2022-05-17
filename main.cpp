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

void UserAddGuest(vector<Table> pTableList, vector<Guest> pGuestsIn) {
	pGuestsIn.push_back(Guest());
	for (int i = 0; i < pTableList.size(); i++) {
		if (pTableList[i].getSeats() > pTableList[i].getGuestNumber()) {
			pTableList[i].seatGuest(pGuestsIn.back());
			break;
		}
		if (i == pTableList.size()) {
			cerr << "Sadly we're fully booked today.";
		}
	}
}

void UserOrder(vector<Drink> pDrinkmenu, vector<Food> pFoodmenu, vector<Guest> pGuestsIn) {
	
	int guestID;

	cout << "Input Guest's ID: " << endl;
	cin >> guestID;
	cout << "Specify your order, type | f | for food or | d | for drink" << endl;
	string UserInput;
	cin >> UserInput;
	if (UserInput == "f") {
		cout << "Select Food Item: " << endl;
		Food::getMenu(pFoodmenu);
		int id;
		cin >> id;
		if (id > pFoodmenu.size() || id < 0) {
			cerr << "Sadly this isn't on the menu";
		}
		else {
			pGuestsIn[guestID - 1].addOrder(new Order(pFoodmenu[id - 1]));
		}
	}
	if (UserInput == "d") {
		cout << "Select Drink Item: " << endl;
		Drink::getMenu(pDrinkmenu);
		int id;
		cin >> id;
		if (id < pDrinkmenu.size() || id < 0) {
			cerr << "Sadly this isn't on the menu";
		}
		else {
			pGuestsIn[guestID - 1].addOrder(new Order(pDrinkmenu[id - 1]));
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
	vector<Guest> GuestsIn;
	Table::loadTables(TableList);
	Drink::loadMenu(Drinkmenu);
	Food::loadMenu(Foodmenu);
	help();
	string UserInput;

	

	//Guest alany;

	//alany.addOrder(&Drinkmenu.at(5-1));
	//alany.addOrder(&Drinkmenu.at(5 - 1));
	//alany.addOrder(&Foodmenu.at(8 - 1));

	//alany.print();

	GuestsIn[0].print();

	while (true) {
		cin >> UserInput;
		if (UserInput == "menu") {
			UserGetMenu(Drinkmenu,Foodmenu);
		}
		if (UserInput == "order") {
			UserOrder(Drinkmenu, Foodmenu,GuestsIn);
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