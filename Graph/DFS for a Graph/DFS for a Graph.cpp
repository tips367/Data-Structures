// DFS for a Graph

#include <iostream>
#include <list>
#include <stack>

class Graph
{
public:
    Graph(int V);

    void addEdge(int v, int w);

    void DFS(int source);

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

void Graph::DFS(int source)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;     // Mark all the vertices as not visited

    // Create a stack for DFS
    std::stack<int> st;

    // Push the current source node.
    st.push(source);

    while (!st.empty())
    {
        // Pop a vertex from stack and print it
        int vertex = st.top();
        st.pop();

        // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
        if (!visited[vertex])
        {
            std::cout << vertex << " ";
            visited[vertex] = true;
        }

        // Get all adjacent vertices of the popped vertex. If a adjacent has not been visited,
        // then push it to stack
        for (auto i = adj[vertex].begin(); i != adj[vertex].end(); i++)
        {
            if (!visited[*i])
            {
                st.push(*i);
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

    std::cout << "Following is Depth First Traversal " << "(starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}


