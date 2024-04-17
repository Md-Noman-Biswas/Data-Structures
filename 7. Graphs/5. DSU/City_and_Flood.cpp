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
const int N = 1e5 + 7;
const int INF = 1e9 + 10;

int parent[N];
int size[N];

void make(int n){
    parent[n] = n;
    size[n] = 1;
}

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}


void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(size[x] < size[y]){
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        make(i);
    }
    while(k--){
        ll u, v;
        cin >> u >> v;
        Union(u, v);
    }
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(find(i) == i){
            cnt++;
        }
    }   
    cout << cnt << nl;
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