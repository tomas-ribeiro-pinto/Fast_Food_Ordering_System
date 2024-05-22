#include "pch.h"
#include "OrderManager.h"

OrderManager::OrderManager(vector<Order> &ordersVector)
{
    orders = PriorityQueue<Order>(ordersVector.size());

    for (Order order : ordersVector)
    {
        Order* ptr = new Order(order);

        // Add orders to queue according to priority
        OrderManager::addToOrderQueue(ptr);
    }

    this->orders = OrderManager::getOrderQueue();
}

OrderManager::~OrderManager()
{
    /*     // Delete orders queue
        for (int i = 0; i < orders.getSize(); i++)
        {
            Order p = orders.remove();
            delete p;
        }

        delete orders; */
}

void OrderManager::addToOrderQueue(Order* order)
{
    orders.insert(order);
}

PriorityQueue<Order> OrderManager::getOrderQueue()
{
    return orders;
}