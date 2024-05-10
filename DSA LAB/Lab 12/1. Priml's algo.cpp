#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define llmx LONG_LONG_MAX
#define llmn LONG_LONG_MIN
#define mod 1000000007
const int N = 1e5 + 7;
const int INF = 1e9 + 10;


int spanningTree(int v, vector<pair<int, int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(v, 0);
    vector<int> parent(v);
    for(int i = 0; i < v; i++){
        parent[i] = i;
    }
    vector<pair<int, pair<int, int>>> mstEdges;
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int wt = node.first;
        int vertex = node.second;

        if(vis[vertex]) continue;
        vis[vertex] = 1;
        sum += wt;
        if(vertex != 0) mstEdges.push_back({wt, {parent[vertex], vertex}});
        for(auto it: adj[vertex]){
            int adjnode = it.first;
            int adj_wt = it.second;
            if(!vis[adjnode]){
                pq.push({adj_wt, adjnode});
                parent[adjnode] = vertex;
            }
        }
    }
    for (auto edge : mstEdges) {
            cout << edge.second.first << "-" << edge.second.second << " -> " << edge.first << nl;
    }
    return sum;
}

void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanningTree(n, adj) << nl;
}

/* Hey you should check this out
    * int overflow, array bounds
    * reset global array and variable
    * look for special cases (n=1?)
    * do something instead of nothing and stay organized
    * bruteforce to find pattern
    * DON'T GET STUCK ON ONE APPROACH
    * Think the problem backwards
    * In practice time don't see failing test case
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
