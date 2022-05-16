#include "Order.h"


using namespace std;
void Order::setPrice(int pPrice)
{
    price = pPrice;
}

int Order::getPrice() const
{
    return price;
}

void Order::setQuantity(double pQuantity)
{
    quantity = pQuantity;
}

double Order::getQuantity() const
{
    return quantity;
}

void Order::print() const
{
    cout << "The Price is: " << price << " Quantity is: " << quantity << endl;
}