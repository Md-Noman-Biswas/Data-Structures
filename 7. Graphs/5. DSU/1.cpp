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

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]); //after recursion call result will also be asigned to parent. cool
}

//almost constant TC
//amortized time complexity
//O(alpha(n))
// alpha(n) -> reverse Ackerman function

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        //union by size
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        make(i);
    }

    while(k--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connected_ct = 0;

    for(int i = 1; i <= n; i++){
        if(find(i) == i) connected_ct++;
    }
    
    cout << connected_ct << nl;

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