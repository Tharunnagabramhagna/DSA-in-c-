#include <iostream>
#include <list>
#include <queue>
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
    bool isCycleDFS(int st)
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
    // Cycle detection using BFS of undirected Graph
    bool isCycleUndirBFS(int src, vector<bool> &vis)
    {
        queue<pair<int, int>> q; // [edge , par]
        q.push({src, -1});
        vis[src] = true;

        while (q.size() > 0)
        {
            int u = q.front().first; // Edge 
            int parU = q.front().second; // par
            q.pop();
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    q.push({v, u}); // v => src ; u => parU
                    vis[v] = true;
                }
                else if (v != parU) // BackEdge Case
                    return true;
            }
        }
        return false;
    }

    bool isCycleBFS(int st)
    {
        int src = st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUndirBFS(src, vis))
                    return true;
            }
        }
        return false;
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

    cout << "Cycle detection using DFS..\n";
    if (g.isCycleDFS(0))
        cout << "The Cycle is detected.\n";
    else
        cout << "The Cycle is not detected.\n";

    Graph g1(5); // seperated graph into two parts

    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(3, 4);

    cout << "Cycle detection using BFS..\n";
    if (g1.isCycleBFS(0))
        cout << "The Cycle is detected.\n";
    else
        cout << "The Cycle is not detected.\n";

    return 0;
}