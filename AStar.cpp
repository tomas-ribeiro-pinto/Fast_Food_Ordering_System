#include "pch.h"
#include "AStar.h"

AStar::AStar(Graph* graph) : graph(graph)
{
    closed = new LinkedList<Node>();
    open = new LinkedList<Node>();
}

Stack<Node>* AStar::reconstructPlan(Node* goal)
{
    Stack<Node>* path = new Stack<Node>(graph->getNumberVertices());
    Node* current = goal;
    while (current->parent != 0)
    {
        path->push(current);
        current = current->parent;
    }
    path->push(current);
    return path;
}

Node* AStar::findLowestNode(LinkedList<Node>* lst)
{
    float lowest = 100000;
    Node* lowestNode = 0;
    Node* current = lst->first;
    while (current != 0)
    {
        if (current->f < lowest)
        {
            lowest = current->f;
            lowestNode = current;
        }
        current = current->next;
    }
    return lowestNode;
}


float AStar::getHeuristic(Location* current, Location* goal)
{
    float dx = goal->x - current->x;
    float dy = goal->y - current->y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

Stack<Node>* AStar::getPath(Location* start, Location* goal)
{
    Node* startNode = new Node(start);
    Node* goalNode = new Node(goal);
    open->insert(startNode);
    while (!open->isEmpty())
    {
        Node* current = findLowestNode(open);
        open->remove(current);
        PriorityQueue<Location>* adjacent = graph->getAdjacentVertices(current->location);
        while (!adjacent->isEmpty())
        {
            Location* adj = adjacent->remove();
            Node* adjNode = new Node(adj);
            adjNode->parent = current;
            if (adjNode->location == goal)
            {
                return reconstructPlan(adjNode);
            }
            adjNode->g = current->g + graph->distanceBetweenVertices(current->location, adj);
            adjNode->h = getHeuristic(adj, goal);
            adjNode->f = adjNode->g + adjNode->h;

            // Check if this node is in the queue of nodes to visit ?
            Node* foundInOpen = open->find(adjNode);
            if (foundInOpen != 0 && foundInOpen->f < adjNode->f)
            {
                continue;
            }
            Node* foundInClosed = closed->find(adjNode);
            if (foundInClosed != 0 && foundInClosed->f < adjNode->f)
            {
                continue;
            }
            open->insert(adjNode);
        }
        closed->insert(current);
    }
    return 0;
}

