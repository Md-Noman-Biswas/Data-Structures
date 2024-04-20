#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    //O(v+e)
    while(!q.empty()){
        int cur_v = q.front();
        cout << cur_v << " ";
        q.pop();
        for(int child: g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    cout << "\n";
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
}