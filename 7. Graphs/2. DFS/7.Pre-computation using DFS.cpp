#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e5+10;

vector<int> g[N];
int subtree_sum[N];
int evenCnt[N];


/*
Given Q queries, Q <= 1e5
int each query given V
print subtree sum of V & Number of even numbers
in subtree of V
*/


void dfs(int vertex, int parent){
    if(vertex % 2 == 0) evenCnt[vertex]++;
    subtree_sum[vertex] += vertex;
    for(int child: g[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        evenCnt[vertex] += evenCnt[child];
    }

}


int main(){
    int n;
    cin >> n; 
    for(int i=1; i<n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1, 0);

    // int q;
    // cin >> q;
    // while(q--){
    //     int v;
    //     cin >> v;
    //     cout << subtree_sum[v] << evenCnt[v] << nl;
    // }

    for(int i=1; i <= n; i++){
        cout << subtree_sum[i] << " " << evenCnt[i] << nl;
    }
}