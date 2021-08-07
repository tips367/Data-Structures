/* Given an undirected graph, check whether the graph contains a cycle or not. Your function should return true
if the given graph contains at least one cycle, else return false.
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
    bool isCyclicRecur(int v, bool visited[], int parent);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicRecur(int v, bool visited[], int parent)
{
	// Mark the current node as visited
	visited[v] = true;

	for (auto i = adj[v].begin(); i != adj[v].end(); i++)
	{
        if (!visited[*i])
        {
            if(isCyclicRecur(*i, visited, v))
                return true;
        }
        // If an adjacent vertex is visited and is not parent of current vertex,
        // then there exists a cycle in the graph.
		else if (*i != parent)
			return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Call the recursive function to detect cycle in different DFS trees
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			if (isCyclicRecur(i, visited, -1))
				return true;
	}

	return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    if (g1.isCyclic())
        std::cout << "Graph contains cycle\n";
    else
        std::cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    
    if (g2.isCyclic())
        std::cout << "Graph contains cycle\n";
    else
        std::cout << "Graph doesn't contain cycle\n";

    return 0;
}


