#pragma once
#include "Order.h"
#include <string>
#include <vector>
#include <fstream>

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

    static void loadMenu(vector<Food>& pFoodmenu);
    static void getMenu(vector<Food>& pFoodmenu);


    string getName()const;
    string getUnit()const;

    void print()const;
};

