#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int parent){

    for(int child: g[vertex]){
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
    
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int max_depth = -1;
    int max_d_node;
    for(int i=1; i<=n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }
    dfs(max_d_node, 0);

    max_depth = -1;

    for(int i=1; i<=n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
        }
    }
    cout << max_depth << nl;
}