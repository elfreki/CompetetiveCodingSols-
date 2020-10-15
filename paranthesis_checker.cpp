
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

void solve() {
	string s;
	cin >> s;
	stack<char> st;
	for (auto x : s) {
		if (x == '(' || x == '{' || x == '[') {
			st.push(x);
		}
		else if (!st.empty() && ((x == ')' && st.top() == '(') || (x == '}' && st.top() == '{') || (x == ']' && st.top() == '[')))
			st.pop();
		else
			st.push(x);
	}
	if (st.empty())
		cout << "balanced\n";
	else
		cout << "not balanced\n";
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