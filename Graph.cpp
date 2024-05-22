#include "pch.h"
#include "Graph.h"

Graph::Graph(int size) : size(size)
{
    numberVertices = 0;
    vertices = new Location * [size];
    // Create a two dimensional array
    adjMat = new double* [size];
    for (int i = 0; i < size; ++i)
        adjMat[i] = new double[size];
    // Initialise 2D array
    for (int n = 0; n < size; n++)
        for (int i = 0; i < size; i++)
        {
            adjMat[n][i] = INF;
        }
}

void Graph::addVertex(Location* vertex)
{
    vertices[numberVertices] = vertex;
    numberVertices++;
}

void Graph::addEdge(int start, int end, float weight = 1)
{
    adjMat[start][end] = weight;
}

PriorityQueue<Location>* Graph::getAdjacentVertices(Location* vertex)
{
    PriorityQueue<Location>* adjacent = new PriorityQueue<Location>(numberVertices);
    for (int j = 0; j < numberVertices; j++)
        if (adjMat[vertex->key][j] != INF)
            adjacent->insert(vertices[j]);
    return adjacent;
}

int Graph::getNumberVertices()
{
    return numberVertices;
}

void Graph::display()
{
    for (int c = 0; c < numberVertices; c++)
    {
        printf(" %c ", vertices[c]->name);
        for (int r = 0; r < numberVertices; r++)
            printf(" %*d", 8, adjMat[c][r]);
        ;
        printf("\n");
    }
}

LinkedList<Location>* Graph::getAdjacentVerticesLL(Location* vertex)
{
    LinkedList<Location>* adjacent = new LinkedList<Location>();
    for (int j = 0; j < numberVertices; j++)
        if (adjMat[vertex->key][j] != INF)
            adjacent->insert(vertices[j]);
    return adjacent;
}

float Graph::distanceBetweenVertices(Location* first, Location* second)
{
    return adjMat[first->key][second->key];
}

Location* Graph::getLowestWeight(LinkedList<Location>* adjacentVertices, Location* vertex)
{
    int lowest = adjacentVertices->first->key;
    double lowestWeight = adjMat[vertex->key][lowest];
    Location* current = adjacentVertices->first->next;
    while (current != NULL)
    {
        if (adjMat[vertex->key][current->key] < lowestWeight)
        {
            lowest = current->key;
            lowestWeight = adjMat[vertex->key][current->key];
        }
        current = current->next;
    }
    return vertices[lowest];
}