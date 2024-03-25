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
const int INF = 1e9 + 10;


vector<pair<int, int>> g[N];
vector<int> level(N, INF);
ll n, m;

int bfs(){
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop_front();
        for(auto child: g[cur_v]){
            int child_v = child.first;
            int wt = child.second;
            if(level[cur_v] + wt < level[child_v]){
                level[child_v] = level[cur_v] + wt; 
                if(wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }
    }

    return level[n] == INF ? -1 : level[n];
}

void solve(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        if(x == y) continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
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
    solve();
    return 0;
}