#pragma once
#include "Location.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include <math.h>

class Graph
{
private:
    static const int INF = 1000000;
    int size;
    int numberVertices;
    double** adjMat;

public:
    Location** vertices;
    Graph(int size);
    void addVertex(Location* vertex);
    void addEdge(int start, int end, float weight);
    PriorityQueue<Location>* getAdjacentVertices(Location* vertex);
    int getNumberVertices();
    void display();
    LinkedList<Location>* getAdjacentVerticesLL(Location* vertex);
    float distanceBetweenVertices(Location* first, Location* second);
    Location* getLowestWeight(LinkedList<Location>* adjacentVerticies, Location* vertex);
};
