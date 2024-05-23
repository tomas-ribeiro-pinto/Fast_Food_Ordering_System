#include "pch.h"
#include "Item.h"

Item::Item(string name, float cost, int numberOfIngredients)
{
    this->name = name;
    this->cost = cost;
    this->numberOfIngredients = numberOfIngredients;
    ingredients = new Ingredient * [numberOfIngredients];
    if (numberOfIngredients == 0)
        ingredients = 0;
    currentCount = 0;
}

Item::~Item()
{
}

string Item::getName()
{
    return this->name;
}

void Item::setCost(float cost)
{
    this->cost = cost;
}

float Item::getCost()
{
    return this->cost;
}

Ingredient** Item::getIngredients()
{
    return this->ingredients;
}

void Item::addIngredient(Ingredient* ingredient)
{
    ingredients[currentCount++] = ingredient;
}

void Item::setIngredients(Ingredient** ingredients)
{
    this->ingredients = ingredients;
}