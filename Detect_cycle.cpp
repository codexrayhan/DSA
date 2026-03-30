
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

bool DFS(int u, int V, int adj[MAX][MAX], int visited[MAX], int recStack[MAX])
{
    visited[u] = 1; //make current node visited
    recStack[u] = 1; // mark current node in recursion stack

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v])
        {
            if (!visited[v] && DFS(v, V, adj, visited, recStack))
                return true; // cycle found in DFS
            else if (recStack[v]) //v is already in the cycle
                return true; // back edge found → cycle
        }
    }

    recStack[u] = 0; // remove node from recursion stack
    return false; //no cycle was found
}

bool isCyclic(int V, int adj[MAX][MAX]) //to check all vertices
{
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
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
        u--; v--; // convert 1-based input to 0-based
        adj[u][v] = 1; // directed edge
    }

    if (isCyclic(V, adj))
        cout << "Graph contains a cycle: Yes" << endl;
    else
        cout << "Graph contains a cycle: No" << endl;

    return 0;
}
