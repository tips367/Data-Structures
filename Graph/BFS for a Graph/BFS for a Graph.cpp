// BFS for a Graph

#include <iostream>
#include <list>
#include <queue>

class Graph
{
public:
    Graph(int V);  

    void addEdge(int v, int w);

    void BFS(int source);

private:
    int V;                  // No. of vertices
    std::list<int>* adj;    // Pointer to an array containing adjacency lists
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list
    adj[v].push_back(w); 
}

void Graph::BFS(int source)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;     // Mark all the vertices as not visited

    // Create a queue for BFS
    std::queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int vertex = q.front();
        std::cout << vertex << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto i = adj[vertex].begin(); i != adj[vertex].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

}

int main()
{
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}


