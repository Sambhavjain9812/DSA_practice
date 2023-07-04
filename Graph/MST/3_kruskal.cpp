#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {

        int mstwt = 0;
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node, adjnode}});
            }
        }
        DisjointSet ds(v);
        sort(edges.begin(), edges.end());
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstwt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstwt;
    }
};