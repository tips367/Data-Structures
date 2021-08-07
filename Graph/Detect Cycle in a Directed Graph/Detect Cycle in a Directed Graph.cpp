/* Given a directed graph, check whether the graph contains a cycle or not. Your function should return true 
if the given graph contains at least one cycle, else return false.
Example, 
 
Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes
*/

#include <iostream>
#include <list>

class Graph
{
public:
    Graph(int V);  
    void addEdge(int v, int w);   
    bool isCyclic();
private:
    int V;   
    std::list<int>* adj;    // Pointer to an array containing adjacency lists
    bool isCyclicRecur(int v, bool visited[], bool recursionStack[]); 
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicRecur(int v, bool visited[], bool recursionStack[])
{
    if (visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recursionStack[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i] && isCyclicRecur(*i, visited, recursionStack))
                return true;
            else if (recursionStack[*i])
                return true;
        }
    }
    // remove the vertex from recursion stack
    recursionStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool* visited = new bool[V];
    bool* recursionStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recursionStack[i] = false;
    }

    // Call the recursive function to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
    {
        if (isCyclicRecur(i, visited, recursionStack))
            return true;
    }

    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        std::cout << "Graph contains cycle";
    else
        std::cout << "Graph doesn't contain cycle";
    return 0;
}


