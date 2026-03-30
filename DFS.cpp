
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void DFS(int u, int V, int adj[MAX][MAX], int visited[MAX])
{
    cout << (u + 1) << " "; // Print current node (convert 0-based to 1-based)
    visited[u] = 1;          // Mark current node as visited

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v] && !visited[v])
            DFS(v, V, adj, visited); // Recursive DFS call
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int adj[MAX][MAX] = {0}; // initially no edges
    int visited[MAX] = {0}; //initially unvisited

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;       // Convert to 0-based indexing
        adj[u][v] = 1;  // Directed edge
        adj[v][u] = 1;  // If undirected, add this line
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;
    start--; // Convert to 0-based

    cout << "DFS Traversal: ";
    DFS(start, V, adj, visited);
    cout << endl;

    return 0;
}
