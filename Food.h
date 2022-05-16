#pragma once
#include "Order.h"
#include <string>

using namespace std;
class Food :
    public Order
{
private:
    string name;
    const string unit = "g";
    bool isVegan;
public:
    Food() :Order(), name(), isVegan(false) {};
    Food(int pPrice, double pQuantity, string pName, bool pVeganStatus) :Order(pPrice, pQuantity), name(pName), isVegan(pVeganStatus) {};
    Food(const Food& other);

    string getName()const;
    string getUnit()const;

    void print()const;
};

