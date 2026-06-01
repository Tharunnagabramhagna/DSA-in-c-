#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int primAlgo(int src, int V, vector<vector<pair<int, int>>> adj)
{
    vector<bool> MstSet(V, false);
    int minCost = 0;

    // min-heap using a priority queue
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
            {                            // neighbors of u
                int v = adj[u][i].first; // u ----> v
                int w = adj[u][i].second;
                if (!MstSet[v])
                    pq.push({w, v});
            }
        }
    }

    return minCost;
}

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

    return 0;
}