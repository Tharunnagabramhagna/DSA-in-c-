#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Edge
{
public:
    int v;
    int wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void DijkstraAlgo(int src, vector<vector<Edge>> g, int V)
{
    vector<int> dist(V, INT_MAX); // INT_MAX represents infinity
    dist[src] = 0;                // set source distance to 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 'greater' and 'vector' are used to create a min-heap priority queue
    // pair: (dist[u], u)

    pq.push({0, src}); // push the source vertex first

    while (pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();
        for (Edge e : g[u])
        { // edge relaxation
            if (dist[e.v] > dist[u] + e.wt)
                dist[e.v] = dist[u] + e.wt;
            pq.push({dist[e.v], e.v}); // push neighbors
        }
    }

    // Print the shortest paths
    cout << "Shortest paths from the source vertex:\n";
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << endl;
}

void bellmanFord(int src,  vector<vector<Edge>> g1, int V1) {
    vector<int>dist(V1,INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < V1-1; i++) {
        // Traverse through each vertex
        for(int u = 0; u < V1; u++) { // u -----> v
            for(Edge e : g1[u]) { // neighours of u
                if(dist[e.v] > dist[u] + e.wt)
                    dist[e.v] = dist[u] + e.wt;
            }
        }
    }

    // Print the shortest paths
    cout << "Shortest Path from the source vertex :\n";
    for(int i = 0; i < V1; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main()
{
    // Dijkstra's Algorithm
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    cout << "\n--Dijkstra's Algorithm--\n";
    DijkstraAlgo(0, g, V);

    // Bellman-ford Algorithm
    int V1 = 5;

    vector<vector<Edge>> g1(V1);

    g1[0].push_back(Edge(1,2));
    g1[0].push_back(Edge(2,4));
    
    g1[1].push_back(Edge(4,-1));
    g1[1].push_back(Edge(2,-4));

    g1[2].push_back(Edge(3,2));
    
    g1[3].push_back(Edge(4,4));

    cout << "\n--Bellman-ford Algorithm--\n";
    bellmanFord(0,g1,V1);

    return 0;
}