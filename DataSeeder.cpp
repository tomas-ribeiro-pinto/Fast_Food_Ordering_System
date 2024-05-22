#include "pch.h"
#include "DataSeeder.h"

DataSeeder::DataSeeder()
{
    DataSeeder::seedIngredients();
    DataSeeder::seedItems();
    DataSeeder::seedOrders();
    DataSeeder::seedRestaurantFloor();
}

DataSeeder::~DataSeeder()
{
    //// Delete ingredients from dynamic array
    //for (int i = 0; i < ingredientsSize; i++)
    //{
    //    delete ingredients[i];
    //}

    //delete[] ingredients;
}

void DataSeeder::seedIngredients()
{
    Ingredient* i1 = new Ingredient("Ketchup");
    Ingredient* i2 = new Ingredient("Mayo");
    Ingredient* i3 = new Ingredient("Lettuce");
    Ingredient* i4 = new Ingredient("Tomato");
    Ingredient* i5 = new Ingredient("Pickles");
    Ingredient* i6 = new Ingredient("Bacon");

    ingredientsSize = 6;

    ingredients = new Ingredient * [ingredientsSize];
    ingredients[0] = i1;
    ingredients[1] = i2;
    ingredients[2] = i3;
    ingredients[3] = i4;
    ingredients[4] = i5;
    ingredients[5] = i6;
}

void DataSeeder::seedItems()
{
    Item i1 = Item("Big Delicious", 4.5, 3);
    i1.addIngredient(ingredients[0]);
    i1.addIngredient(ingredients[2]);
    i1.addIngredient(ingredients[5]);
    items.push_back(i1);

    Item i2 = Item("Tasty Bun", 7.75, 6);
    i2.setIngredients(ingredients);
    items.push_back(i2);

    Item i3 = Item("Natura Burger", 3.75, 0);
    items.push_back(i3);

    Item i4 =  Item("Max Bacon", 5.25, 3);
    i4.addIngredient(ingredients[1]);
    i4.addIngredient(ingredients[2]);
    i4.addIngredient(ingredients[5]);
    items.push_back(i4);
}

void DataSeeder::seedOrders()
{
    vector<Item> o1Items;
    o1Items.push_back(items[0]);
    o1Items.push_back(items[1]);
    o1Items.push_back(items[1]);
    Order o1 = Order("Sam Smith", OrderType::Collection, o1Items);
    orders.push_back(o1);

    vector<Item > o2Items;
    o2Items.push_back(items[0]);
    o2Items.push_back(items[3]);
    Order o2 = Order("Beth Simpson", OrderType::Drive, o2Items);
    orders.push_back(o2);

    vector<Item> o3Items;
    o3Items.push_back(items[2]);
    Order o3 = Order("Grace Petrie", OrderType::Table, o3Items, 4);
    orders.push_back(o3);

    vector<Item> o4Items;
    o4Items.push_back(items[0]);
    o4Items.push_back(items[1]);
    o4Items.push_back(items[2]);
    o4Items.push_back(items[3]);
    Order o4 = Order("Mark Sanderson", OrderType::Collection, o4Items);
    orders.push_back(o4);
}

void DataSeeder::seedRestaurantFloor()
{
    graph = new Graph(16);

    //Create tables and collection Counter
    Location* collectionCounter = new Location(0, "A1", 0, 0);
    Location* table1 = new LocationTable(1, 12, "D1", 0, 3);
    Location* table2 = new LocationTable(2, 9, "C2", 1, 2);
    Location* table3 = new LocationTable(3, 2, "A3", 2, 0);
    Location* table4 = new LocationTable(4, 7, "B4", 3, 1);
    Location* table5 = new LocationTable(5, 15, "D4", 3, 3);

    tables.push_back(collectionCounter);
    tables.push_back(table1);
    tables.push_back(table2);
    tables.push_back(table3);
    tables.push_back(table4);
    tables.push_back(table5);

    // Create and add the remaining vertices part of the restaurant floor
    graph->addVertex(tables[0]);
    graph->addVertex(new Location(1, "A2", 1, 0));
    graph->addVertex(tables[3]);
    graph->addVertex(new Location(3, "A4", 3, 0));
    graph->addVertex(new Location(4, "B1", 0, 1));
    graph->addVertex(new Location(5, "B2", 1, 1));
    graph->addVertex(new Location(6, "B3", 2, 1));
    graph->addVertex(tables[4]);
    graph->addVertex(new Location(8, "C1", 0, 2));
    graph->addVertex(tables[2]);
    graph->addVertex(new Location(10, "C3", 2, 2));
    graph->addVertex(new Location(11, "C4", 3, 2));
    graph->addVertex(tables[1]);
    graph->addVertex(new Location(13, "D2", 1, 3));
    graph->addVertex(new Location(14, "D3", 2, 3));
    graph->addVertex(tables[5]);

    // Add the connecting edges to create the restaurant floor.
    // IMPORTANT: This floor is set for only one way journeys to tables. 
    // There are no return journeys from tables as edges only connect from left to right 
    // Diagonal movements are square root of 2 in terms of weight
    graph->addEdge(0, 1, 1);
    graph->addEdge(0, 4, 1);
    graph->addEdge(0, 5, sqrt(2));
    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 5, 1);
    graph->addEdge(1, 6, sqrt(2));
    graph->addEdge(2, 3, 1);
    graph->addEdge(2, 6, 1);
    graph->addEdge(2, 7, sqrt(2));
    graph->addEdge(3, 2, 1);
    graph->addEdge(3, 7, 1);
    graph->addEdge(4, 0, 1);
    graph->addEdge(4, 5, 1);
    graph->addEdge(4, 1, sqrt(2));
    graph->addEdge(4, 9, sqrt(2));
    graph->addEdge(4, 8, 1);
    graph->addEdge(5, 1, 1);
    graph->addEdge(5, 2, sqrt(2));
    graph->addEdge(5, 6, 1);
    graph->addEdge(5, 10, sqrt(2));
    graph->addEdge(5, 9, 1);
    graph->addEdge(6, 2, 1);
    graph->addEdge(6, 3, sqrt(2));
    graph->addEdge(6, 7, 1);
    graph->addEdge(6, 10, 1);
    graph->addEdge(6, 11, sqrt(2));
    graph->addEdge(7, 3, 1);
    graph->addEdge(7, 11, 1);
    graph->addEdge(8, 4, 1);
    graph->addEdge(8, 5, sqrt(2));
    graph->addEdge(8, 9, 1);
    graph->addEdge(8, 13, sqrt(2));
    graph->addEdge(8, 12, 1);
    graph->addEdge(9, 5, 1);
    graph->addEdge(9, 6, sqrt(2));
    graph->addEdge(9, 10, 1);
    graph->addEdge(9, 14, sqrt(2));
    graph->addEdge(9, 13, 1);
    graph->addEdge(10, 6, 1);
    graph->addEdge(10, 7, sqrt(2));
    graph->addEdge(10, 11, 1);
    graph->addEdge(10, 14, 1);
    graph->addEdge(10, 15, sqrt(2));
    graph->addEdge(11, 7, 1);
    graph->addEdge(11, 15, 1);
    graph->addEdge(12, 8, 1);
    graph->addEdge(12, 9, sqrt(2));
    graph->addEdge(12, 13, 1);
    graph->addEdge(13, 9, 1);
    graph->addEdge(13, 10, sqrt(2));
    graph->addEdge(13, 14, 1);
    graph->addEdge(14, 10, 1);
    graph->addEdge(14, 11, sqrt(2));
    graph->addEdge(14, 15, 1);
}