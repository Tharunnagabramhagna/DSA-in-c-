#include <iostream>
#include <list>
#include <queue>
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
    { // O(1)
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList()
    { // O(n^2)
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int vertex : l[i])
                cout << vertex << " ";
            cout << endl;
        }
    }

    // BFS traversal //
    void BFS(int st)
    {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(st); // push source vertex first
        vis[0] = true;

        while (q.size() > 0)
        {
            int u = q.front(); // u => source vertex
            q.pop();
            cout << u << " ";
            for (int v : l[u])
            { // v => destination vertex
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    // DFS traversal //
    void helper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
                helper(v, vis);
        }
    }

    void DFS()
    {
        int src = 0;
        vector<bool> vis(V, false);
        helper(src, vis);

        // for disconnected graphs
        // for(int i = 0; i < V; i++) {
        //     if(!vis[i])
        //         helper(i,vis);
        // }
    }
};

int main()
{
    Graph g(5); // T.C = O(V)

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    cout << "The Adjacency List : \n";
    g.printAdjList();

    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 4);
    cout << "\nBFS traversal : ";
    int source = 0;
    g1.BFS(source);
    cout << endl;
    cout << "DFS traversal : ";
    g1.DFS();
    cout << endl;

    return 0;
}