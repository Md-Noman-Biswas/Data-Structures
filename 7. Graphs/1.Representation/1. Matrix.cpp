#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

int graph[N][N];//space complexity N^2
//if N > N^6 the we cant store it using matrix preprentation.

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    // to check if connected or not
    // if(graph[1][1] == 1){
    //     //connected
    // }
}