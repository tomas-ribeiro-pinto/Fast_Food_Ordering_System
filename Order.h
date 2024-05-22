#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

// Types of order: Drive-Thru, Collection at counter, Delivered to a table
enum OrderType
{
    Drive,
    Collection,
    Table
};

class Order
{
private:
    int orderNumber;
    string customerName;
    int tableNumber;
    OrderType orderType;
    vector<Item> items;
    bool isServed;
    static int currentOrderNumber;

public:
    int priorityCost;
    Order(string customerName, OrderType orderType, vector<Item> items, int tableNumber = 0);

    ~Order();
    string getCustomerName();
    int getOrderNumber();
    int getTableNumber();
    void setTableNumber(int tableNumber);
    OrderType getOrderType();
    string getOrderTypeLabel();
    vector<Item> getItems();
    void addItem(Item* item);
    void removeItem(Item *item);
    void serveOrder(PriorityQueue<Order>& v);
    void displayOrder();
    void displayFullOrder();
    float getTotalCost();
    int getOrderSize();
    bool operator>(const Order& rhd);
    void setPriorityCost();
    // static Factorial Function
    static int factorial(int n);
};