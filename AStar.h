#pragma once
#include "Node.h"
#include "Stack.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Graph.h"

class AStar
{
private:
    LinkedList<Node>* closed; // Nodes visited
    LinkedList<Node>* open;   // Nodes to be processed
    Stack<Node>* path;
    Graph* graph;
    Stack<Node>* reconstructPlan(Node* goal);
    Node* findLowestNode(LinkedList<Node>* lst);
    float getHeuristic(Location* current, Location* goal);

public:
    AStar(Graph* graph);
    Stack<Node>* getPath(Location* start, Location* goal);
};


