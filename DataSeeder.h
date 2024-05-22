#pragma once
#include <iostream>
#include <string>
#include "Order.h"
#include "Item.h"
#include "Ingredient.h"
#include "PriorityQueue.h"
#include "Graph.h"
#include "Node.h"
#include "AStar.h"
#include "Stack.h"
#include "Location.h"
#include "LocationTable.h"
#include <vector>
#include <cmath>

using namespace std;

class DataSeeder
{
public:
    vector<Order> orders;
    vector<Item> items;
    vector<Location *> tables;
    Graph *graph;
    Ingredient** ingredients;
    int ingredientsSize;
    DataSeeder();
    ~DataSeeder();
    void seedIngredients();
    void seedItems();
    void seedOrders();
    void seedRestaurantFloor();
};
