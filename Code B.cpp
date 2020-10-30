//Ojas Kumar Dubey //
// el_freki //
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define ordered_set tree<int, null_type,les<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define pii pair <int , int>
#define fi first
#define se second
#define setp(x) setprecision(x)
#define meme(x,i) memset(x,i,sizeof(x))
const int N = 200001;
void solve() {
	int n;
	cin >> n;
	int a[n + 1], nxtg[n + 1], nxts[n + 1], prevg[n + 1], prevs[n + 1];
	f(i, 1, n + 1) {
		cin >> a[i];
	}
	stack<int> s;
	f(i, 1, n + 1) {
		while (!s.empty() && a[i] >= a[s.top()]) {
			nxtg[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		nxtg[s.top()] = n + 1;
		s.pop();
	}
	r(i, n + 1, 1) {
		while (!s.empty() && a[i] >= a[s.top()]) {
			prevg[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		prevg[s.top()] = 0;
		s.pop();
	}
	r(i, n + 1, 1) {
		while (!s.empty() && a[i] <= a[s.top()]) {
			prevs[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		prevs[s.top()] = 0;
		s.pop();
	}
	f(i, 1, n + 1) {
		while (!s.empty() && a[i] <= a[s.top()]) {
			nxts[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		nxts[s.top()] = n + 1;
		s.pop();
	}
	int ans[n + 5];
	f(i, 0, n + 5) {
		ans[i] = n - 1;
	}
	ans[1] = 0;
	f(i, 1, n + 1) {
		/*cout << prevs[i] << " " << prevg[i] << endl;
		cout << ans[prevs[i]] << " " << ans[prevg[i]] << endl;*/
		ans[i] = min(ans[prevs[i]] + 1, ans[i]);
		ans[i] = min(ans[i], ans[prevg[i]] + 1);
		//cout << ans[i] << endl;
		ans[nxtg[i]] = min(ans[nxtg[i]], ans[i] + 1);
		ans[nxts[i]] = min(ans[nxts[i]], ans[i] + 1);
		ans[i + 1] = min(ans[i + 1], ans[i] + 1);
	}
	/*f(i, 1, n + 1) {
		cout << ans[i] << " ";
	}
	cout << endl;*/
	cout << ans[n];
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
