#pragma once
#include "Order.h"
#include <string>
#include <vector>
#include <fstream>


using namespace std;
class Drink :
    public Order
{
private:
    string name;
    const string unit = "L";
    bool isAlcoholic;
public:
    Drink() :Order(), name(), isAlcoholic(false) {};
    Drink(int pPrice, double pQuantity, string pName, bool pAlcoholStatus) :Order(pPrice, pQuantity), name(pName), isAlcoholic(pAlcoholStatus) {};
    Drink(const Drink& other);

    static void loadMenu(vector<Drink> &pDrinkmenu);
	static void getMenu(vector<Drink> &pDrinkmenu);

    string getName()const;
    string getUnit()const;

    void print()const;

};