/* Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances 
from s to all other vertices in the given graph.*/

#include <iostream>
#include <list>
#include <stack>
#include <utility>

class Graph
{
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void longestPath(int source);
private:
    int V;
    std::list<std::pair<int, int>>* adj;    // Pointer to an array containing adjacency lists
    void topologicalSortUtil(int v, bool visited[], std::stack<int>& st);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<std::pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    adj[u].push_back({v, weight});
}

void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int>& st)
{
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
    {
        if (!visited[i->first])
            topologicalSortUtil(i->first, visited, st);
    }

    // Push current vertex to stack which stores topological sort
    st.push(v);
}

void Graph::longestPath(int source)
{
    std::stack<int> st;
    int* distance = new int[V];

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            topologicalSortUtil(i, visited, st);
    }

    // Initialize distances to all vertices as -ve infinite and distance to source as 0
    for (int i = 0; i < V; i++)
        distance[i] = INT_MIN;
    distance[source] = 0;

    // Process vertices in topological order
    while (st.empty() == false) 
    {
        int u = st.top();
        st.pop();

        // Update distances of all adjacent vertices
        if (distance[u] != INT_MIN) 
        {
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
            {
                distance[i->first] = std::max(distance[i->first], distance[u] + i->second);
            }
        }
    }

    // Print the calculated longest distances
    for (int i = 0; i < V; i++)
        (distance[i] == INT_MIN) ? std::cout << "INF " : std::cout << distance[i] << " ";

    delete[] visited;
    delete[] distance;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int source = 1;
    std::cout << "Following are longest distances from source vertex " << source << " \n";
    g.longestPath(source);

    return 0;
}



