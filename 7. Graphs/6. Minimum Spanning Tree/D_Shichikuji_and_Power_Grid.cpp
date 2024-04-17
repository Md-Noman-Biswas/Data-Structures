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
const int N = 2e3 + 7;
const int INF = 1e9 + 10;

int parent[N];
int size_array[N];
multiset<int> sizes;

void make(int n){
    parent[n] = n;
    size_array[n] = 1;
    sizes.insert(1);
}

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(size_array[a]));
    sizes.erase(sizes.find(size_array[b]));

    sizes.insert(size_array[a] + size_array[b]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(size_array[x] < size_array[y]){
            swap(x, y);
        }
        parent[y] = x;
        merge(x, y);
        size_array[x] += size_array[y];
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll, int>> cities(n + 1); 

    for(int i = 1; i <=n; i++){
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> c(n + 1), k(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> k[i];

    vector<pair<ll, pair<int, int>>> edges;

    for(int i = 1; i <= n; i++){
        edges.push_back({c[i], {0, i}});
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            ll cost = dist * 1LL * (k[i] + k[j]);
            edges.push_back({cost, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());

    make(0);
    for(int i = 1; i <= n; i++) make(i);

    ll total_cost = 0;
    vector<int> power_stations;
    vector<pair<int, int>> connections;

    //minimum spanning tree
    for(auto edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u, v);
        total_cost += wt;

        if(u == 0 || v == 0){
            power_stations.push_back(max(u, v)); // non zero value
        }else{
            connections.push_back({u, v});
        }
        //cout << u << " " << v << nl;
    }

    cout << total_cost << nl;
    cout << power_stations.size() << nl;
    for(auto it: power_stations){
        cout << it << " ";
    }
    cout << nl;

    cout << connections.size() << nl;
    for(auto it: connections){
        cout << it.first << " " << it.second << nl;
    }
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