/* Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every 
directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible 
if the graph is not a DAG.*/

#include <iostream>
#include <list>
#include <stack>

class Graph
{
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
private:
    int V;
    std::list<int>* adj;    // Pointer to an array containing adjacency lists
    void topologicalSortUtil(int v, bool visited[], std::stack<int>& st);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int>& st)
{
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, st);
    }

    // Push current vertex to stack which stores topological sort
    st.push(v);
}

void Graph::topologicalSort()
{
    std::stack<int> st;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            topologicalSortUtil(i, visited, st);
    }

    // Print contents of stack
    while (st.empty() == false) 
    {
        std::cout << st.top() << " ";
        st.pop();
    }

    delete[] visited;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::cout << "Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}


