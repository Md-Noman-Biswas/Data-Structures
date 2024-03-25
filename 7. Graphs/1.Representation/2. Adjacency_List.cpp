#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e3;

// int graph[N][N];
vector<int> graph2[N];

//space complexity -> O(vertices + edges) -> O(n + m)
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        // graph[v1][v2] = 1;
        // graph[v2][v1] = 1;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
}