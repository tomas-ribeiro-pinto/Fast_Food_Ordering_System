#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"
#include "Order.h"

using namespace std;

class OrderManager
{
private:
    PriorityQueue<Order> orders;

public:
    OrderManager(vector<Order> &ordersVector);
    ~OrderManager();
    void addToOrderQueue(Order* order);
    PriorityQueue<Order> getOrderQueue();
};
