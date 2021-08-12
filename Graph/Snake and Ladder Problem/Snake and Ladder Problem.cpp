/* Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell 
from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum 
number of throws required to reach last cell.
If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if reaches a cell is
mouth of the snake, has to go down to the tail of snake without a dice throw.
*/

#include <iostream>
#include <queue>

// An entry in queue used in BFS
struct Node
{
    int vertex;    // Vertex number
    int distance;  // Distance of this vertex from source
};

int getMinDiceThrows(int moves[], int N)
{
    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;     // Mark all the cells as not visited

    // Create a queue for BFS
    std::queue<Node> q;

    // Mark the node 0 as visited and enqueue it
    visited[0] = true;
    Node s = { 0, 0 }; 
    q.push(s);

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        if (node.vertex == N - 1)
            return node.distance;

        for (int i = node.vertex + 1; (i <= node.vertex + 6) && (i < N); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;

                Node n;
                n.distance = node.distance + 1;

                // Check if there a snake or ladder at 'i' then tail of snake or top of ladder
                // become the adjacent
                if (moves[i] != -1)
                    n.vertex = moves[i];
                else
                    n.vertex = i;
                q.push(n);

            }
        }
           
    }
}

int main()
{
    int N = 30;
    int* moves = new int[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    std::cout << "Min Dice throw required is " << getMinDiceThrows(moves, N);
    return 0;
}

