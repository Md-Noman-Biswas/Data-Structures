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
const int N = 510;
const int INF = 1e9 + 10;

ll dist[N][N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }
    vector<ll> deletion_order(n);
    for(int i = 0; i < n; i++){
        cin >> deletion_order[i];
    }
    vector<ll> ans;
    reverse(deletion_order.begin(), deletion_order.end());
    for(int k = 0; k < n; k++){
        ll k_v = deletion_order[k];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }
        ll sum = 0;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                sum += dist[deletion_order[i]][deletion_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans){
        cout << it << " ";
    }
    cout << nl;
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