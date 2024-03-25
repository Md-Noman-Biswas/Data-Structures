#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define llmx LONG_LONG_MAX
#define llmn LONG_LONG_MIN
#define mod 1000000007
const int N = 1e3 + 7;
const int inf = 1e9 + 10;

int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;

vector<pair<int, int>> movements = {
    {0, 1}, {0, -1}, 
    {1, 0}, {-1, 0},
    {1, 1}, {1, -1},
    {-1, 1}, {-1, -1},
};

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(){
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mx = max(mx, val[i][j]);
        }
    }

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mx == val[i][j]){
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;

    while(!q.empty()){
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();

        for(auto movement: movements){
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x, child_y});
            level[child_x][child_y] = level[v_x][v_y] + 1;
            ans = max(ans, level[child_x][child_y]);
            vis[child_x][child_y] = 1;
        }
    }

    return ans;
}


void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = 0;
            level[i][j] = inf;
        }
    }
}

void solve(){
    reset();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> val[i][j];
        }
    }
    cout << bfs() << "\n";
}



/* Hey you should check this out
    * int overflow, array bounds
    * reset global array and variable
    * look for special cases (n=1?)
    * do something instead of nothing and stay organized
    * bruteforce to find pattern
    * DON'T GET STUCK ON ONE APPROACH
    * Think the problem backwards
    * In practice time don't see failing test case
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}