#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

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
        l[u].push_back(v); // only for directed graphs
    }

    // Cycle Detection for directed graph under DFS
    bool helperDFS(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        // Mark source vertex as visited
        vis[src] = true;
        recPath[src] = true;

        for (int v : l[src])
        {
            if (!vis[v])
            {
                if (helperDFS(v, vis, recPath))
                    return true; // cycle found
            }
            else if (recPath[v])
                return true; // cycle found
        }

        recPath[src] = false; // cycle not found
        return false;
    }

    bool CycleDetectionDirDFS()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (helperDFS(i, vis, recPath))
                    return true; // cycle found
            }
        }
        return false; // cycle not found
    }
};

int main()
{
    Graph g(4);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3,0);

    cout << "DFS in Directed Graph :\n";
    if(g.CycleDetectionDirDFS())
        cout << "Cycle is Detected.\n";
    else
        cout << "Cycle is not Detected.\n";

    return 0;
}