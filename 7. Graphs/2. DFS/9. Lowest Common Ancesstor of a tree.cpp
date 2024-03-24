#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> g[N];
int parents[N];

void dfs(int vertex, int parent = -1){

    parents[vertex] = parent;
    for(int child: g[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
    }

}

vector<int> path(int v){

    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = parents[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}

//O(n)
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int x, y;
    cin >> x >> y;
    dfs(1);
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mn_ln = min(path_x.size(), path_y.size());
    int lca = -1;
    for(int i=0; i<mn_ln; i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }else{
            break;
        }
    }
    cout << lca << "\n";
}