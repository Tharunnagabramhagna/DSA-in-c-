#include <iostream>
#include <queue>
#include <vector>
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

    return 0;
}