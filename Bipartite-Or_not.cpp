
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int adj[100][100], int V)
{
    int color[100];
    for (int i = 0; i < V; i++) //initialize all vertices as uncoloured
        color[i] = -1;  // -1 means uncoloured

    for (int start = 0; start < V; start++) //bfs checked all vertex handling disconnected graph
    {
        if (color[start] == -1) //if ot color yet
        {
            queue<int> q; //create bfs queue
            q.push(start);
            color[start] = 0; //colour the start vertex

            while (!q.empty()) //untill queue empty
            {
                int u = q.front(); //pick the front vertex from queue
                q.pop(); //and pop

                for (int v = 0; v < V; v++) //for checked every neighbours of u
                {
                    if (adj[u][v]) //if there is an edge between them
                    {
                        if (color[v] == -1) // and if v is uncoloured
                        {
                            color[v] = 1 - color[u]; //colour v with the opposite colur of u
                            q.push(v);
                        }
                        else if (color[v] == color[u]) //same colour as u
                        {
                            return false; //not bipartite
                        }
                    }
                }
            }
        }
    }
    return true; //bfs find all components without same colour means graph bipartite
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100] = {0};

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) //loop to read E edges
    {
        int u, v;
        cin >> u >> v;

        u--; //for don't ignore vetex 0
        v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (isBipartite(adj, V))
        cout << "Graph is Bipartite: Yes\n";
    else
        cout << "Graph is Bipartite: No\n";

    return 0;
}
