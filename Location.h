#pragma once
#include <iostream>
#include <string>

using namespace std;

class Location
{
public:
    int key;
    string name;
    float x, y;
    bool wasVisited;
    // pointer to the next location if in a linked list
    Location* next;

    Location(int key, string name, float x, float y) : key(key), name(name), x(x), y(y) {}

    bool operator==(const Location& rhd)
    {
        return this->key == rhd.key;
    }
    bool operator!=(const Location& rhd)
    {
        return this->key != rhd.key;
    }
    bool operator>(const Location& rhd)
    {
        return this->key > rhd.key;
    }
    bool operator<(const Location& rhd)
    {
        return this->key < rhd.key;
    }
    void display()
    {
        cout << name << " Coord. X:" << x << " Y: " << y << endl;
    }
};
