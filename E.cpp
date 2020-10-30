#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define X first
#define Y second
using namespace std;
int const N = 2e5 + 5;
vector< vector<int> > adj(N);
int in[N], out[N], cur = 0;
int prt[N], depth[N];
void dfs(int u){
    in[u] = cur++;
    for(int v: adj[u]){
        if(v == prt[u]) continue;
        prt[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    out[u] = cur++;
}
bool is_parent(int u, int v){
    return in[u] < in[v] && out[u] > out[v];
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false), cin.tie(0),cout.tie(0);
#endif
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while(q--){
        int k;
        cin>>k;
        int v[k];
        int x, mx = -1;
        for(int i=0; i<k; i++){
            cin >> v[i];
            if(depth[v[i]] > mx){
                mx = depth[v[i]];
                x = v[i];
            }
        }
        bool ans = true;
        for(int i=0; i<k; i++){
            if(v[i] == 1 || v[i] == x) continue;
            v[i] = prt[v[i]];
            if(!is_parent(v[i], x)){
                ans = false;
                break;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";


    }
}
