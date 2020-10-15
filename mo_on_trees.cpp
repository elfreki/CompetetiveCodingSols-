
//Inshallah , Boys played well..!!

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
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
#define pii pair <int , int>
#define fi first
#define se second
#define setp(x) setprecision(x)
#define meme(x,i) memset(x,i,sizeof(x))
const int N = 100005;
const int syz = 500;

int n, m;
vector<int> g[N];
bool vis[2 * N], nodefreq[2 * N];
int cur_time = 0, flat[2 * N], in[N], out[N], depth[N], ans[N], freq[N];
int val[N];
int parent[N][20], c1 = 0;

//query struct
struct query {
	int lt, rt, idx, lcaxy;
	bool chk;
} Q[N];


//query comparator
bool cmp(query q1, query q2) {
	if (q1.lt / syz != q2.lt / syz)
		return q1.lt / syz < q2.lt / syz;
	return q1.rt < q2.rt;
}


//dfs
void dfs(int node) {
	in[node] = ++cur_time;
	f(i, 1, 20) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
	}
	vis[node] = 1;
	for (auto x : g[node]) {
		if (!vis[x]) {
			depth[x] = depth[node] + 1;
			parent[x][0] = node;
			dfs(x);
		}
	}
	out[node] = ++cur_time;
}


//lca
int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	r(i, 20, 0) {
		if (depth[x] <= depth[parent[y][i]])
			y = parent[y][i];
	}
	if (x == y) {
		return x;
	}
	r(i, 20, 0) {
		if (parent[x][i] != parent[y][i])
			x = parent[x][i], y = parent[y][i];
	}
	return parent[x][0];
}

//calculate the freq. of node and freq of value at node and distinct values
void freq_calc(int id) {
	if (!nodefreq[flat[id]]) {
		nodefreq[flat[id]] = true;
		freq[val[flat[id]]]++;
		if (freq[val[flat[id]]] == 1)
			c1++;
	}
	else {
		nodefreq[flat[id]] = false;
		if (freq[val[flat[id]]] == 1) {
			c1--;
		}
		freq[val[flat[id]]] = max(0, freq[val[flat[id]]] - 1);
	}
}


void solve() {

	cin >> n >> m;

	meme(parent, -1);

	pii vp[n];

	//input value at nodes
	f(i, 1, n + 1) {
		cin >> val[i];
		vp[i] = {val[i], i};
	}

	sort(vp + 1, vp + n + 1);

	c1 = 1;

	val[vp[1].se] = c1;

	f(i, 2, n + 1) {
		if (vp[i - 1].fi < vp[i].fi)
			c1++;
		val[vp[i].se] = c1;
	}

	c1 = 0;

	//tree input
	f(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y), g[y].pb(x);
	}

	depth[1] = 0;

	f(i, 0, 20) {
		parent[1][i] = 1;
	}

	dfs(1);

	//flat repressent node at times
	f(i, 1, n + 1) {
		flat[in[i]] = flat[out[i]] = i;
	}

	//taking input of queries
	f(i, 0, m) {
		int x, y;
		cin >> x >> y;
		if (depth[y] < depth[x]) {
			swap(x, y);
		}
		Q[i].idx = i;
		Q[i].lcaxy = lca(x, y);
		if (Q[i].lcaxy == x) {
			Q[i].lt = in[x], Q[i].rt = in[y], Q[i].chk = false;
		}
		else {
			Q[i].lt = out[x], Q[i].rt = in[y], Q[i].chk = true;
		}
	}

	//sort queries
	sort(Q, Q + m, cmp);

	int l = 1, r = 1;

	c1 = 1;

	freq[val[flat[1]]] = 1, nodefreq[flat[1]] = true;

	f(i, 0, m) {
		while (r < Q[i].rt) {
			r++;
			freq_calc(r);
		}
		while (l < Q[i].lt) {
			freq_calc(l);
			l++;
		}
		while (Q[i].rt < r) {
			freq_calc(r);
			r--;
		}
		while (Q[i].lt < l) {
			l--;
			freq_calc(l);
		}
		ans[Q[i].idx] = c1;
		if (Q[i].chk && freq[val[Q[i].lcaxy]] == 0) {
			ans[Q[i].idx]++;
		}
	}
	f(i, 0, m) {
		cout << ans[i] << endl;
	}
}

int main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--)  solve();
}
