#include "Table.h"
#include "Guest.h"
#include "Order.h"
#include "Drink.h"
#include "Food.h"

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {

	Drink* Drinks[30];

	ifstream drinkmenu;
	int tmpPrice;
	double tmpQuant;
	string tmpName;
	int tmpState;
	
	int j = 0;

	drinkmenu.open("drinkmenu.txt", ifstream::in);
	if (!drinkmenu.is_open()) {
		cout << "error while opening the file";
	}
	else {
		cout << "reading from the file contetns" << endl;
		int i = 0;
		while (!drinkmenu.eof()) {
			
			drinkmenu >> tmpName >> tmpPrice >> tmpQuant >> tmpState;
			if (tmpState == 1) {
				Drinks[i] = new Drink(tmpPrice, tmpQuant, tmpName, true);
			}
			else {
				Drinks[i] = new Drink(tmpPrice, tmpQuant, tmpName, false);
			}
			i++;
			j++;
		}

	}

	//cout << tmpPrice << " " << tmpQuant << " " << tmpName << " " << tmpState << endl;

	for (int i = 0; i < j; i++) {
		Drinks[i]->print();
	}

	drinkmenu.close();



	return 0;
}