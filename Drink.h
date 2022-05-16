#pragma once
#include "Order.h"
#include <string>
using namespace std;
class Drink :
    public Order
{
private:
    string name;
    const string unit = "dl";
    bool isAlcoholic;
public:
    Drink(int pPrice, double pQuantity, string pName, bool pAlcoholStatus) :Order(pPrice, pQuantity), name(pName), isAlcoholic(pAlcoholStatus) {};
    Drink(const Drink& other);

    string getName()const;
    string getUnit()const;

    void print()const;
};

