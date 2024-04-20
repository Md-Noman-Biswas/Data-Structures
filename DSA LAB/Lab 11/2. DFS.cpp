#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
//vector<vector<int>> g;
bool vis[N];

void dfs(int source){
    stack<int> st;
    st.push(source);
    vis[source] = true;

    while (!st.empty()){
        int vertex = st.top();
        st.pop();
        cout << vertex << " ";

        for (int i = 0; i < g[vertex].size(); i++){
            int child = g[vertex][i];
            if (!vis[child]){
                st.push(child);
                vis[child] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // for(auto it: g){
    //     for(auto it2: it){
    //         if(!vis[it2]){
    //             dfs(it2);
    //         }
    //     }
    // }

    dfs(1);
}
