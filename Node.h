#pragma once
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Node
{
public:
    float g;
    float f;
    float h;
    Location* location;
    Node* next;
    Node* parent;
    Node(Location* location);
    bool operator!=(const Node& rhd);
    bool operator==(const Node& rhd);
};