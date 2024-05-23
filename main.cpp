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
    // Seed the application with dummy data
    DataSeeder* data = new DataSeeder();

    // Pass the orders created to a Order Manager object and get a 
    // priority queue of the orders acording to priority cost
    OrderManager* orderManager = new OrderManager(data->orders);
    PriorityQueue<Order> orders = orderManager->getOrderQueue();

    // Display the ordering screen and pass the restaurant floor plan seeded
    DisplayManager* displayManager = new DisplayManager(orders, data->graph, data->tables);
    displayManager->display();

    return 0;
}