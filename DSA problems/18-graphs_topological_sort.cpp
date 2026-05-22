#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

// Topological Sort works for DAG only
// DAG => Directed Acyclic Graph

class Graph {
    int V;
    list<int>*l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u,int v) {
        l[u].push_back(v);
    }
    void DFS(int curr, vector<bool>& vis, stack<int>& s) {
        vis[curr] = true;
        for(int v : l[curr]) {
            if(!vis[v])
                DFS(v,vis,s);
        }
        s.push(curr);
    }
    void topoSort() {
        vector<bool>vis(V,false);
        stack<int> s;
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                DFS(i,vis,s);
        }
        while(s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(2,3);
    g.addEdge(4,1);
    g.addEdge(3,1);

    cout << "The topological Order of the Graph is : \n";
    g.topoSort();

    return 0;
}