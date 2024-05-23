#pragma once
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

/*
* The Node class contains the heuristic and other value costs of a 
* Location when performing an A star path finding algorithm.
* It also serves as an assistant class to the LinkedList class to identify the next value of the chain
*/
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