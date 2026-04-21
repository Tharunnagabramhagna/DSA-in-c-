#include <iostream>
#include <list>
#include <vector>
using namespace std;

/* In Undirected and Directed Graphs */

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // Helper function
    bool isCycleUndirDFS(int src, int par, vector<bool> &vis)
    {                    // O(V+E)
        vis[src] = true; // mark vis
        for (int v : l[src])
        {
            if (!vis[v])
            {
                // checking for next nodes until DFS found
                if (isCycleUndirDFS(v, src, vis))
                    return true;
            }
            else if (v != par) // cycle found here
                return true;
        }
        return false; // cycle is not found
    }
    // Cycle detection using DFS of undirected Graph
    bool isCycle(int st)
    {
        vector<bool> vis(V, false);
        int src = st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUndirDFS(src, -1, vis)) // cycle found
                    return true;
            }
        }
        return false; // cycle not found
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    if (g.isCycle(0))
        cout << "The Cycle is detected.\n";
    else
        cout << "The Cycle is not detected.\n";

    return 0;
}