#pragma once
#include <iostream>
#include <string>
#include "Ingredient.h"

using namespace std;

class Item
{
private:
    string name;
    float cost;
    Ingredient** ingredients;
    int numberOfIngredients;
    int currentCount;

public:
    Item(string name, float cost, int numberOfIngredients);
    ~Item();
    string getName();
    float getCost();
    void setCost(float cost);
    Ingredient** getIngredients();
    void addIngredient(Ingredient* ingredient);
    void setIngredients(Ingredient** ingredients);
};