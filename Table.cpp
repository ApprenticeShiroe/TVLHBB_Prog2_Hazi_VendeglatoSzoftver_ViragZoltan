#include "Table.h"

using namespace std;
Table::Table(const Table& other)
{
	tableId = other.tableId;
	seats = other.seats;
	guestNumber = other.guestNumber;
	for (int i = 0; i < guestNumber; i++) {
		guests[i] = other.guests[i];
	}
}

int Table::getTableId() const
{
	return tableId;
}

int Table::getGuestNumber() const
{
	return guestNumber;
}

int Table::getSeats() const
{
	return seats;
}

void Table::loadTables(vector<Table> &pTableList)
{
	ifstream tableFile;
	tableFile.open("tables.txt", ifstream::in);
	if (!tableFile.is_open()) {
		cerr << "Error while trying to open file!";
	}
	else {
		cout << "Reading from talbes.txt" << endl;
		int tmpId, tmpSeats;
		while (!tableFile.eof()) {
			tableFile >> tmpId >> tmpSeats;
			pTableList.push_back(Table(tmpId, tmpSeats));
		}
	}
	tableFile.close();
}

void Table::seatGuest(Guest& pGuest)
{
	guests.push_back(pGuest);
	guestNumber++;
}

void Table::leavingGuest(int guestId)
{
	for (int i = 0; i < guestNumber; i++) {
		if (guests[i].getId() == guestId) {
			guests.erase(guests.begin() + i - 1);
		}
	}
}


void Table::print() const
{
	cout << "Table's ID: " << tableId << " Available seats: " << seats << endl;
}
