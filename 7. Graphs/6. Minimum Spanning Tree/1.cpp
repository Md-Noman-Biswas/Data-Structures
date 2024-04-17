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
multiset<int> sizes;

void make(int n){
    parent[n] = n;
    size[n] = 1;
    sizes.insert(1);
}

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));

    sizes.insert(size[a] + size[b]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(size[x] < size[y]){
            swap(x, y);
        }
        parent[y] = x;
        merge(x, y);
        size[x] += size[y];
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < k; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

    for(int i = 1; i <= n; i++) make(i);

    int total_cost = 0;
    for(auto edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u, v);
        total_cost += wt;
        //cout << u << " " << v << nl;
    }
    cout << total_cost << nl;
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