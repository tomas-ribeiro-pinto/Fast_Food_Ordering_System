#include "pch.h"

#include <iostream>
#include <string>
#include "DataSeeder.h"
#include "DisplayManager.h"
#include "OrderManager.h"
#include "Order.h"

using namespace std;

int Order::currentOrderNumber = 0;

int main()
{
    DataSeeder* data = new DataSeeder();
    OrderManager* orderManager = new OrderManager(data->orders);

    PriorityQueue<Order> orders = orderManager->getOrderQueue();
    DisplayManager* displayManager = new DisplayManager(orders, data->graph, data->tables);
    displayManager->display();
    return 0;
}