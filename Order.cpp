#include "pch.h"
#include "Order.h"

// Constructor for Order: items can be set at a later stage, and tableNumber is optional
// TODO: Aditional checks need to be implemented for checking the existance of a table number
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

void Order::serveOrder(PriorityQueue<Order> &v)
{
    isServed = true;
    v.remove();
}

/*
* Short Order summary
*/
void Order::displayOrder()
{
    cout << "#" << Order::getOrderNumber() << " | " << Order::getOrderTypeLabel() << endl;
    cout << "Customer: " << Order::getCustomerName() << " | Items: " << items.size() << endl;
}

/*
* Full Order summary
*/
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

/*
* Get total cost of order
*/
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

/*
* returns the number of items in an order
*/
int Order::getOrderSize()
{
    return items.size();
}

/*
* Operator overload for comparing priority cost
*/
bool Order::operator>(const Order& rhd)
{
    return priorityCost > rhd.priorityCost;
}

/*
* Set the priority cost according to number of items in an order and type of order.
* Drive Thu orders get priority over other orders.
* TODO: This algorithm needs to be modified in the future to take into consideration time of ordering.
*/
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

/*
* Recursive function that calculates the factorial value of a number
*/
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