
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

bool BFS(int V, int adj[MAX][MAX], int src, int dest, int parent[MAX]) //bfs func for find shortest path
{
    int visited[MAX] = {0};
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    parent[src] = -1; //since source has no parent

    while (!q.empty()) //bfs loop
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) //explore neighbours
        {
            if (adj[u][v] && !visited[v])
            {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);

                if (v == dest)
                    return true; // destination found
            }
        }
    }
    return false; // destination not reachable
}

// Function to print path from src to dest using parent array
void printPath(int dest, int parent[MAX])
{
    int path[MAX];
    int count = 0;
    int current = dest;

    while (current != -1) //untill src parent
    {
        path[count++] = current;
        current = parent[current];
    }

    cout << "Shortest Path: ";
    for (int i = count - 1; i >= 0; i--) //print in correct order
    {
        cout << path[i] + 1; // convert 0-based index to 1-based
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int adj[MAX][MAX] = {0};

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--; // convert 1-based to 0-based
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;
    src--; dest--; // convert to 0-based

    int parent[MAX]; //print path
    if (BFS(V, adj, src, dest, parent))
        printPath(dest, parent);
    else
        cout << "No path exists from " << src + 1 << " to " << dest + 1 << endl;

    return 0;
}
