#pragma once
#include "Guest.h"
#include <iostream>
class Table
{
private:
	int tableId;
	int seats;
	Guest* guests;
public:
	Table() :tableId(0), seats(0), guests(nullptr) {};
	Table(int pId, int pSeats) :tableId(pId), seats(pSeats), guests(nullptr) {};
	Table(const Table& other);
	~Table();



	void print()const;
};

