#pragma once
#include <iostream>
#include <string>
#include "PriorityQueue.h"
#include "Order.h"
#include "Graph.h"
#include <vector>
#include "Location.h"
#include "AStar.h"

using namespace std;

class DisplayManager
{
private:
    Order* currentOrder;

public:
    PriorityQueue<Order> orders;
    vector<Location*> tables;
    Graph* restaurantFloor;
    int maxOrders;
    DisplayManager(PriorityQueue<Order> orders, Graph* graph, vector<Location *> &tables);
    ~DisplayManager();
    void display();
    void displayOrders();
    void chooseScreen(char& option);
};