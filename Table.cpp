#include "Table.h"

using namespace std;
Table::Table(const Table& other)
{
	tableId = other.tableId;
	seats = other.seats;
	guests = other.guests;
}

Table::~Table()
{
	delete[] guests;
}

void Table::print() const
{
	cout << "Table's ID: " << tableId << " Available seats: " << seats << endl;
}
