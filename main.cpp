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

void UserGetMenu(vector<Drink> pDrinkmenu) {
	Drink::getMenu(pDrinkmenu);
}


int main() {
	vector<Drink> Drinkmenu;
	//vector<Food> FoodMenu;
	string UserInput;
	Drink::loadMenu(Drinkmenu);

	


	Guest alany;

	alany.addOrder(&Drinkmenu.at(5-1));
	alany.addOrder(&Drinkmenu.at(5 - 1));
	alany.addOrder(&Drinkmenu.at(8 - 1));

	alany.print();


	/*

	Guest alany2;
	alany2.print();
	Drink a(*Drinks[2]);
	alany2.addOrder(new Drink(a));


	alany2.print();

	alany2.removeOrders();

	*/

	while (true) {
		cin >> UserInput;
		if (UserInput == "menu") {
			UserGetMenu(Drinkmenu);
		}






		if (UserInput == "exit") {
			return 0;
		}
	}



	return 0;
}