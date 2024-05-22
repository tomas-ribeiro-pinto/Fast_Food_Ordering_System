#include "pch.h"
#include "LocationTable.h"


LocationTable::LocationTable(int tableNumber, int key, string name, float x, float y) : Location(key, name, x, y)
{
	this->tableNumber = tableNumber;
}

int LocationTable::getTableNumber()
{
	return tableNumber;
}