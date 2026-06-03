#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int primAlgo(int src, int V, vector<vector<pair<int, int>>> adj)
{
    vector<bool> MstSet(V, false);
    int minCost = 0;

    // Min-heap using a priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // [edge weight, vertex]

    while (pq.size() > 0)
    {
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();

        if (!MstSet[u])
        {
            MstSet[u] = true; // mark as visited
            minCost += wt;    // add the edge weight

            for (int i = 0; i < adj[u].size(); i++)
            {                            // Neighbors of u
                int v = adj[u][i].first; // u ----> v
                int w = adj[u][i].second;
                if (!MstSet[v])
                    pq.push({w, v});
            }
        }
    }

    return minCost;
}

class Edge
{
public:
    int u;
    int v;
    int wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    // comparator => "<"
    bool operator<(const Edge &obj) const
    {
        return this->wt < obj.wt;
    }
};

class Graph
{
public:
    int V;
    vector<Edge> edges;
    vector<int> par, rank;
    Graph(int V)
    {
        this->V = V;
        for (int i = 0; i < V; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(int u, int v, int wt)
    {
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x)
    {
        // Base Case
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]); // path compression
    }

    void unionFind(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        // Edge Case => used for cycle detection too
        if (parA == parB)
            return;

        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
            par[parB] = parA;
        else
            par[parA] = parB;
    }

    void kruskal()
    { // O(E logE)
        // sort the edges
        sort(edges.begin(), edges.end());
        int mstCost = 0; // store result
        int count = 0;

        for (int i = 0; i < edges.size() && count < V - 1; i++)
        {
            Edge e = edges[i]; // the edges
            // parents of u and v
            int parU = find(e.u);
            int parV = find(e.v);
            if (parU != parV)
            {
                unionFind(parU, parV); // linking to min wt vertices 
                mstCost += e.wt; // Adding of wt
                count++; // optimization till V-1 edges
            }
        }

        cout << "Cost of MST : " << mstCost << endl;
    }
};

int main()
{
    int V = 4;

    vector<vector<pair<int, int>>> adj(V);

    // undirected graph: (vertex, weight)

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[3].push_back({2, 50});
    adj[2].push_back({3, 50});

    cout << "\n--Prim's Algorithm--\n";
    cout << "Cost of MST: " << primAlgo(0, V, adj) << endl;
    cout << endl;

    int V1 = 6;

    vector<vector<pair<int, int>>> adj1(V1); // v, wt

    adj1[0].push_back({5, 10});
    adj1[5].push_back({0, 10});
    adj1[5].push_back({4, 25});
    adj1[4].push_back({5, 25});
    adj1[4].push_back({3, 22});
    adj1[3].push_back({4, 22});
    adj1[3].push_back({2, 12});
    adj1[2].push_back({3, 12});
    adj1[2].push_back({1, 16});
    adj1[1].push_back({2, 16});

    cout << "\nCase with no edge removals:\n";
    cout << "Cost of MST: " << primAlgo(0, V1, adj1) << endl;
    cout << endl;

    // Kruskal's Algorithm

    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(3, 2, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 2, 6);

    cout << "\n--Kruskal's Algorithm--\n";
    g.kruskal();
    cout << endl;

    return 0;
}