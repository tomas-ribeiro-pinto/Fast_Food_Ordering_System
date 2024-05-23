#include "pch.h"
#include "DisplayManager.h"

DisplayManager::DisplayManager(PriorityQueue<Order> orders, Graph* graph, vector<Location *> &tables) : orders(orders)
{
    // Initialise maximum of orders shown in screen
    maxOrders = 4;
    restaurantFloor = graph;
    this->tables = tables;
}

DisplayManager::~DisplayManager()
{
    // Clear tables vector and delete other dynmaic variables
    tables.clear();

    delete restaurantFloor;
    delete currentOrder;
}

void DisplayManager::display()
{
    cout << "Welcome to FastFood Ordering System!" << endl;
    cout << "#####################################\n"
        << endl;
    cout << endl;
    if (orders.getCurrentSize() > 0)
    {
        // Display orders according to priority queue
        DisplayManager::displayOrders();

        cout << endl;
        cout << "Options:" << endl;
        cout << "1 - Serve first order" << endl;
        cout << "2 - Expand first order details" << endl;
        cout << "\n Choose an option: " << endl;

        char option = '0';
        cin >> option;
        DisplayManager::chooseScreen(option);
    }
    else
    {
        cout << "## NO ORDERS PLACED! ##" << endl;
    }

}

void DisplayManager::chooseScreen(char& option)
{
    switch (option)
    {
    case '1':
    {
        if (currentOrder->getOrderType() == OrderType::Table)
        {
            AStar* astar = new AStar(restaurantFloor);
            Stack<Node>* path = astar->getPath(tables[0], tables[currentOrder->getTableNumber()]);
            int pathSize = path->count();
            
            cout << "\nThis order needs to be taken to table: " << currentOrder->getTableNumber() << endl;
            cout << "This is the shortest route to the table:\n" << endl;

            for (int i = 0; i < pathSize; i++)
            {
                path->pop()->location->display();
            }

            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        currentOrder->serveOrder(orders);
        this->display();
        break;
    }
    case '2':
    {
        currentOrder->displayFullOrder();
        this->display();
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        DisplayManager::chooseScreen(option);
    }
    }
}

/**
 * Display priority orders
 */
void DisplayManager::displayOrders()
{
    // Temporary queue
    PriorityQueue<Order> tempOrders = orders;
    currentOrder = tempOrders.peakMin();

    for (int i = 0; i < maxOrders; i++)
    {
        // escape loop when i is greater than the curent size of elements
        if (i > orders.getCurrentSize() - 1)
            break;

        Order* tempOrder = tempOrders.remove();
        tempOrder->displayOrder();
    }
}