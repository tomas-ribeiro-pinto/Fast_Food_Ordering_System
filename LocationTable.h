#pragma once
#include "Location.h"
#include <string>

using namespace std;

/*
* Subclass of Location that asigns a table at a set of cordinates
*/
class LocationTable : public Location
{
public:
	int tableNumber;
	LocationTable(int tableNumber, int key, string name, float x, float y);
	int getTableNumber();
};

