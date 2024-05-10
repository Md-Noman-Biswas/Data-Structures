#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            parent[ulp_v] += size[ulp_u];
        }
    }

    void UnionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int spanning_tree(vector<pair<int, int>> adj[], int v){
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < v; i++){
        for(auto it: adj[i]){
            int node = i;
            int adjnode = it.first;
            int wt = it.second;
            edges.push_back({wt, {node, adjnode}});
        }
    }
    
    DisjointSet ds(v);
    sort(edges.begin(), edges.end());
    int edgeWt = 0;
    vector<int> parent(v, 0);
    for(int i = 0; i < v; i++) parent[i] = i;
    vector<pair<int, pair<int, int>>> spanning_edges;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        parent[v] = u;
        if(ds.findPar(u) != ds.findPar(v)){
            ds.UnionBySize(u, v);
            edgeWt += wt;
            spanning_edges.push_back({wt, {u, v}});
        }
    }
    for(auto it: spanning_edges){
        cout << it.second.first << " - " << it.second.second << "-> " << it.first << "\n";
    }
    return edgeWt;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanning_tree(adj, n) << "\n";
}