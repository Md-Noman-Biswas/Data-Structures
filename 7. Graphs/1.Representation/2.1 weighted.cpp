#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e3;

// int graph[N][N];
vector<pair<int, int>> graph2[N];

//space complexity -> O(vertices + edges) -> O(n + m)
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        // graph[v1][v2] = wt;
        // graph[v2][v1] = wt;

        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
    }
    //to check connected or not
    // for(int child: graph2[i]){
    //     if(child == j){
    //         //connected
    //     }
    // }
    /*
    in a weighted graph
    for(pair<int, int> child: graph2[i]){
        if(child.first == j){
            weight->child.second
        }
    }
    */
}