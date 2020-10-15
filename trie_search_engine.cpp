
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

struct trie {
	trie *bache[26];
	bool isend;
};

trie* getnode(void) {
	trie *nn = new (struct trie);
	nn->isend = false;
	for (int i = 0; i < 26; i++)
		nn->bache[i] = NULL;
	return nn;
}

void insert(trie *root, string s) {
	trie *pp = root;
	for (int i = 0; i < s.size(); i++) {
		if (!pp->bache[s[i] - 'a']) {
			pp->bache[s[i] - 'a'] = getnode();
		}
		pp = pp->bache[s[i] - 'a'];
	}
	pp->isend = true;
}

bool find(trie *root, string s) {
	trie *pp = root;
	f(i, 0, sz(s)) {
		if (!pp->bache[s[i] - 'a']) {
			return false;
		}
		pp = pp->bache[s[i] - 'a'];
	}
	if (pp->isend)
		return true;
	return false;
}

void solve() {
	trie *root = getnode();
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		insert(root, s);
	}
	cin >> s;
	if (find(root, s))
		cout << 1 << endl;
	else
		cout << "0\n";
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