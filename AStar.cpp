#include "pch.h"
#include "AStar.h"

AStar::AStar(Graph* graph) : graph(graph)
{
    // Initialise list of nodes to visit and processed
    closed = new LinkedList<Node>();
    open = new LinkedList<Node>();
}

/*
* Return the shortest path found by inverting the Linked list of nodes
* with a stack to reconstruct the path to get to the goal
*/
Stack<Node>* AStar::reconstructPlan(Node* goal)
{
    Stack<Node>* path = new Stack<Node>(graph->getNumberVertices());
    Node* current = goal;
    while (current->parent != 0)
    {
        // push current node to the stack and move to next node in the list
        path->push(current);
        current = current->parent;
    }
    path->push(current);

    // return the stack
    return path;
}

/*
* Return the lowest node in a linked list in terms of movement cost 
* by adding the weight cost between vertices and the heuristic value
*/
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


/*
* Return the heuristic value that defines the distance to the goal node using the Pythagorean theorem
*/
float AStar::getHeuristic(Location* current, Location* goal)
{
    // Get the difference between coordinates (distance)
    float dx = goal->x - current->x;
    float dy = goal->y - current->y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}


/*
* Find the shortest path between start and goal locations
*/
Stack<Node>* AStar::getPath(Location* start, Location* goal)
{
    // Create nodes to store locations and respective movement costs
    Node* startNode = new Node(start);
    Node* goalNode = new Node(goal);

    // insert the starting node in the list of nodes to visit
    open->insert(startNode);

    // run a loop while there is nodes to visit
    while (!open->isEmpty())
    {
        // get the lowest node of the nodes to visit, so that the closest node is visited first
        Node* current = findLowestNode(open);
        // remove the node form the list to visit
        open->remove(current);
        // get the adjacent vertices priority queue of the current location being processed
        PriorityQueue<Location>* adjacent = graph->getAdjacentVertices(current->location);

        // run a loop while the adjacent list is not empty
        while (!adjacent->isEmpty())
        {
            // get the first adjacent location of the queue and insert it into a node
            Location* adj = adjacent->remove();
            Node* adjNode = new Node(adj);
            // set the parent of the node to be the current node being processed 
            adjNode->parent = current;

            // if the adjacent vertice is the goal location, then the shortest path has been found
            if (adjNode->location == goal)
            {
                // reconstruct the shortest path
                return reconstructPlan(adjNode);
            }

            // Add movement costs (g= sum of weights; h=heuristic; f=sum of g with h)
            adjNode->g = current->g + graph->distanceBetweenVertices(current->location, adj);
            adjNode->h = getHeuristic(adj, goal);
            adjNode->f = adjNode->g + adjNode->h;

            // Check if this node is in the queue of nodes to visit or visited and if the adjacent node's f cost is greater
            // if it is greater, this current path being processed is not the shortest path and 
            // another adjacent is processed instead by jumping to the next adjacent in the loop 
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

            // insert the adjacent node in nodes list to visit
            open->insert(adjNode);
        }

        // insert the current node in the list of nodes already visited 
        closed->insert(current);
    }
    return 0;
}

