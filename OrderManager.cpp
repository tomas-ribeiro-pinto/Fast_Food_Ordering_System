#include "pch.h"
#include "OrderManager.h"

OrderManager::OrderManager(vector<Order> &ordersVector)
{
    orders = PriorityQueue<Order>(ordersVector.size());

    for (Order order : ordersVector)
    {
        Order* ptr = new Order(order);

        // Add orders to queue according to priority cost
        OrderManager::addToOrderQueue(ptr);
    }

    this->orders = OrderManager::getOrderQueue();
}

OrderManager::~OrderManager()
{
}

void OrderManager::addToOrderQueue(Order* order)
{
    orders.insert(order);
}

PriorityQueue<Order> OrderManager::getOrderQueue()
{
    return orders;
}