#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int parent){

    vis[vertex] = true;
    bool isLoopExists = false;
    for(int child: g[vertex]){
        if(vis[child] && child == parent) continue;
        if(vis[child]) return true;
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;

}


void solve(){
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);    
    }
    int ct = 0;
    bool isLoopExists = false;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        bool flag = dfs(i, 0);
        if(flag) isLoopExists = true;
        ct++;
    }
    if(isLoopExists){
        cout << 1 << nl;
    }else{
        cout << 0 << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}