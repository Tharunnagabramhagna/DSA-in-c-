#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Topic :- Finding Strongly Connected Componenets using Kosaraju's Algorithm

class Graph
{
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    { // directed graph
        adj[u].push_back(v);
    }

    // topological sort logic
    void topoSort(int curr, vector<bool> &vis, stack<int> &s)
    {
        vis[curr] = true;
        for (int neigh : adj[curr])
        {
            if (!vis[neigh])
                topoSort(neigh, vis, s);
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool> &vis, vector<vector<int>> &transpose)
    {
        vis[curr] = true;
        cout << curr << " ";
        for (int neigh : transpose[curr])
        {
            if (!vis[neigh])
                dfs(neigh, vis, transpose);
        }
    }

    void kosarajuAlgo()
    { // T.C => O(V+E)
        // step-1 => topological sort => O(V+E)
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topoSort(i, vis, s);
        }

        // step-2 => transpose graph => O(V+E)
        vector<vector<int>> transpose(V);
        for (int u = 0; u < V; u++)
        { // u ---> v
            vis[u] = false;
            for (int v : adj[u]) // v ---> u
                transpose[v].push_back(u);
        }

        // step-3 => DFS with stack nodes on transpose => O(V+E)
        cout << "Strongly connected components of the graph : \n";
        while (s.size() > 0)
        {
            int curr = s.top();
            s.pop();
            if (!vis[curr])
            {
                dfs(curr, vis, transpose); // SSC
                cout << endl; // seperate each SSC with new line 
            }
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    g.kosarajuAlgo(); // Printing the output

    return 0;
}