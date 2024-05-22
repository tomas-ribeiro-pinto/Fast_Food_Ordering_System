#include "pch.h"
#include "Order.h"

// Constructor for Order: items can be set at a later stage, and tableNumber is optional
Order::Order(string customerName, OrderType orderType, vector<Item> items, int tableNumber)
{
    this->items = items;

    if (tableNumber != 0)
    {
        this->tableNumber = tableNumber;
    }

    this->customerName = customerName;
    this->orderType = orderType;
    this->isServed = false;
    this->orderNumber = ++Order::currentOrderNumber;

    Order::setPriorityCost();
}

Order::~Order()
{
}

int Order::getOrderNumber()
{
    return this->orderNumber;
}

string Order::getCustomerName()
{
    return this->customerName;
}

int Order::getTableNumber()
{
    return this->tableNumber;
}

void Order::setTableNumber(int tableNumber)
{
    this->tableNumber = tableNumber;
}

OrderType Order::getOrderType()
{
    return orderType;
}

string Order::getOrderTypeLabel()
{
    switch (orderType)
    {
    case 0:
        return "Drive Thru";
    case 1:
        return "Bag Collection";
    case 2:
        return "Table Service";
    }

    return "Other";
}

vector<Item> Order::getItems()
{
    return this->items;
}

void Order::addItem(Item* item)
{
    items.push_back(*item);
}

void Order::removeItem(Item *item)
{
    //vector<Item>::iterator res;
    //res = find(items.begin(), items.end(), item);
    //items.erase(res);
} 

void Order::serveOrder(PriorityQueue<Order> &v)
{
    isServed = true;
    v.remove();
}

void Order::displayOrder()
{
    cout << "#" << Order::getOrderNumber() << " | " << Order::getOrderTypeLabel() << endl;
    cout << "Customer: " << Order::getCustomerName() << " | Items: " << items.size() << endl;
}

void Order::displayFullOrder()
{
    cout << endl;
    cout << "#####################################" << endl;
    cout << "Type of Order: " << Order::getOrderTypeLabel() << endl;

    if (tableNumber > 0)
    {
        cout << "Table Number: " << tableNumber << endl;
    }

    cout << "Order Number:" << Order::getOrderNumber()
        << " | Customer: " << Order::getCustomerName() << endl;
    cout << "Items: " << endl;

    for (Item item : items)
    {
        cout << " - " << item.getName() << endl;
    }

    cout << "###############################(######" << endl;
    cout << "TOTAL: " << Order::getTotalCost() << endl;
    cout << "#####################################" << endl;
    cout << endl;
}

float Order::getTotalCost()
{
    vector<Item>::iterator it;
    vector<Item>::iterator res;

    float totalCost = 0;

    for (Item item : items)
    {
        totalCost += item.getCost();
    }

    return totalCost;
}

int Order::getOrderSize()
{
    return items.size();
}

bool Order::operator>(const Order& rhd)
{
    return priorityCost > rhd.priorityCost;
}

void Order::setPriorityCost()
{
    int size = Order::getOrderSize();

    if (Order::getOrderType() == OrderType::Drive)
    {
        priorityCost = factorial(size - 1);
    }
    else
    {
        priorityCost = factorial(size);
    }
}

int Order::factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else if (n == 1)
        return 1;
    else
        return 0;
}