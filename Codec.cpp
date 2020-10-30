#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;*/
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define find_by_order(container,k) *container.find_by_order(k)
#define order_of_key(container,key) container.order_of_key(key)
#define endl '\n'
#define ll long long
#define pb push_back
#define pf push_front
#define mk make_pair
#define f(i,j,n) for(ll i=j;i<n;i++)
#define r(i,n,j) for(ll i=n-1;i>=j;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Test int t;cin>>t;while(t--)
#define mod 1000000007
#define md 998244353
#define MIN INT_MIN
#define MAX INT_MAX
#define inf LLONG_MAX
#define all(container) container.begin() , container.end()
#define rall(container) container.rbegin() , container.rend()
#define sz(container) (int)container.size()
#define v vector<long long>
#define pii pair <ll , ll>
#define fi first
#define se second
#define setp(x) setprecision(x)
const int N = 100005;
v graph[N];
bool vis[N];
ll nn[N];
void dfs1(int u) {
	vis[u] = true;
	for (auto i : graph[u]) {
		if (vis[i])
			continue;
		dfs1(i);
		nn[u] += nn[i];
	}
}
void solve() {
	int n, k, x, y;
	cin >> n ;
	f(i, 0, n + 1)
	vis[i] = false;
	f(i, 1, n) {
		nn[i] = 1;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	nn[n] = 1;
	dfs1(1);
	ll m;
	cin >> m;
	ll mm[m];
	f(i, 0, m)
	cin >> mm[i];
	sort(mm, mm + m);
	ll ans[n + 1], ans1 = 0;
	f(i, 1, n + 1) {
		nn[i] = nn[i] * (n - nn[i]);
		ans[i] = 1;
	}
	sort(nn + 1, nn + n + 1);
	int j = m - 1;
	if (n <= m) {
		while (m != n - 1) {
			ans[n] = ((ans[n] % mod) * (mm[j] % mod)) % mod;
			j--, m--;
		}
	}
	r(i, n + 1, 1) {
		if (0 <= j)
			ans[i] = ((ans[i] % mod) * (mm[j] % mod)) % mod;
		else
			ans[i] = 1;
		j--;
	}
	r(i, n + 1, 2) {
		ans1 = (ans1 % mod + ((ans[i] % mod) * (nn[i] % mod)) % mod) % mod;
	}
	cout << ans1 << endl;
	f(i, 0, n + 1) {
		graph[i].clear();
	}
}

int main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--)  solve();
}
