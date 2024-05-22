#include "pch.h"
#include "Node.h"

Node::Node(Location* location)
{
    this->location = location;
    this->g = 0;
    this->f = 0;
    this->h = 0;
    this->next = 0;
    this->parent = 0;
}

bool Node::operator!=(const Node& rhd)
{
    return location->key != rhd.location->key;
}

bool Node::operator==(const Node& rhd)
{
    return location->key == rhd.location->key;
}