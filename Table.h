#pragma once
#include "Guest.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Table
{
private:
	int tableId;
	int seats;
	int guestNumber;
	Guest* guests[];
public:
	Table() :tableId(0), seats(0), guestNumber(0), guests() {};
	Table(int pId, int pSeats) :tableId(pId), seats(pSeats), guests(),guestNumber(0) {};
	Table(const Table& other);
	~Table();

	int getTableId()const;

	static void loadTables(vector<Table> &pTableList);

	void seatGuest(Guest* pGuest);
	void leavingGuest(int guestId);

	void print()const;
};

