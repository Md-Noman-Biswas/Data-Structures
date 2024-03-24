#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 300;
vector<int> g[N];

//leetcode flood fill question
void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){


        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;//range shold be 0 to n-1 & m-1
        if(grid[i][j] != '1') return;

        grid[i][j] = '2';   // 2 -> visited
        dfs(i-1, j, n, m, grid);
        dfs(i+1, j, n, m, grid);
        dfs(i, j-1, n, m, grid);
        dfs(i, j+1, n, m, grid);

}

int numIslands(vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( grid[i][j] == '1'){
                    dfs(i, j, n, m, grid);
                    cnt++;   
                }                  
            }
        }
        return cnt;

}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<9; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}