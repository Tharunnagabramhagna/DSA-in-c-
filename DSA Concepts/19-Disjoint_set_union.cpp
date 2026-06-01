#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion
{
public:
    int n;
    vector<int> par, rank;

    DisjointSetUnion(int n)
    {
        this->n = n;
        // Initialization of vectors
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        // Edge case: if vertices are already linked
        if (parA == parB)
            return;

        if (rank[parA] == rank[parB])
        { // Case 1: equal ranks
            par[parB] = parA;
            rank[parA]++;
        }
        // Case 2: higher rank for parA
        else if (rank[parA] > rank[parB])
            par[parB] = parA;
        // Case 3: lower rank for parA
        else
            par[parA] = parB;
    }

    int find(int x)
    {
        // Base case
        if (par[x] == x)
            return x;

        // Recursive case
        return par[x] = find(par[x]); // path compression
    }

    void getInfo()
    {
        cout << "Final values of par and rank vectors:\n";
        for (int val : par)
            cout << val << " ";
        cout << endl;
        for (int val : rank)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout << "Position of 2: " << dsu.find(2) << endl;
    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);
    cout << "Position of 2: " << dsu.find(2) << endl;
    dsu.unionByRank(0, 4);
    dsu.getInfo();

    return 0;
}