/* A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that 
every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every 
edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is 
no edge that connects vertices of same set.
*/

#include <iostream>
#include <vector>
#include <queue>

bool isBipartiteComponent(std::vector<int> adj[], int node, std::vector<int>& color)
{
    std::queue<int> q;
    q.push(node);
    color[node] = 1;

    //Process current graph component using BFS
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int ele : adj[curr])
        {
            // Odd-cycle
            if (color[ele] == color[curr])
                return false;
            // Unvisited node
            if (color[ele] == -1)
            {
                color[ele] = 1 - color[curr];
                q.push(ele);
            }

        }
    }
    return true;
}

bool isBipartite(std::vector<int> adj[], int V)
{
    // vector to store colour of vertex
    // assiging all to -1 i.e. uncoloured
    // colours are either 0 or 1 for understanding take 0 as red and 1 as blue
    std::vector<int> color(V, -1);

    //loop in case graph is not connected
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartiteComponent(adj, i, color))
                return false;
        }
    }
    return true;
}

int main()
{
    //adjacency list for storing graph
    std::vector<int> adj[4];
    adj[0] = { 1,3 };
    adj[1] = { 0,2 };
    adj[2] = { 1,3 };
    adj[3] = { 0,2 };

    if (isBipartite(adj, 4))
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}


