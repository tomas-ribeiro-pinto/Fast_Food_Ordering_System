#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ingredient
{
public:
    string name;
    Ingredient(string name) : name(name) {};
    Ingredient() {};
    ~Ingredient() {};
};