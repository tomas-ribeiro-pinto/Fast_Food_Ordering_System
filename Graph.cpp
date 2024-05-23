#include "pch.h"
#include "Graph.h"

Graph::Graph(int size) : size(size)
{
    // current number of vertices
    numberVertices = 0;
    vertices = new Location * [size];

    // Create a two dimensional array that stores the weight cost values between adjacent vertices
    adjMat = new float* [size];
    for (int i = 0; i < size; ++i)
        adjMat[i] = new float[size];

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

/*
* Set a conection between two vertices (Edge) and add its weight cost to 2D array
*/
void Graph::addEdge(int start, int end, float weight = 1)
{
    adjMat[start][end] = weight;
}

/*
* Return a priority queue with adjacent vertices to a vertex
*/
PriorityQueue<Location>* Graph::getAdjacentVertices(Location* vertex)
{
    PriorityQueue<Location>* adjacent = new PriorityQueue<Location>(numberVertices);
    for (int j = 0; j < numberVertices; j++)
        if (adjMat[vertex->key][j] != INF)
            adjacent->insert(vertices[j]);
    return adjacent;
}

/*
* Return current number of vertices
*/
int Graph::getNumberVertices()
{
    return numberVertices;
}

/*
* Display vertices and weight costs of edges
*/
void Graph::display()
{
    for (int c = 0; c < numberVertices; c++)
    {
        cout << vertices[c]->name << endl;
        for (int r = 0; r < numberVertices; r++)
            cout << adjMat[c][r] << endl;
        ;
        printf("\n");
    }
}

/*
* Return distance between vertices
*/
float Graph::distanceBetweenVertices(Location* first, Location* second)
{
    return adjMat[first->key][second->key];
}

/*
* Get the lowest weight cost of the adjacent vertices
*/
Location* Graph::getLowestWeight(LinkedList<Location>* adjacentVertices, Location* vertex)
{
    // set the lowest adjacent vertice key to be the first of the list
    int lowestVertex = adjacentVertices->first->key;
    // set the lowest weight cost according to 2D array
    float lowestWeight = adjMat[vertex->key][lowestVertex];

    // Perform a search in the list
    Location* current = adjacentVertices->first->next;
    while (current != NULL)
    {
        // if the current element of the search has a lower weight cost
        // change lowestVertex and lowestWeight variables to the new lowest vertex values
        if (adjMat[vertex->key][current->key] < lowestWeight)
        {
            lowestVertex = current->key;
            lowestWeight = adjMat[vertex->key][current->key];
        }
        // move to the next element of the list
        current = current->next;
    }

    // return the location of the lowest vertex
    return vertices[lowestVertex];
}