#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
/* #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
 */ 
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
#define vll vector<long long>
#define vi vector<int>
#define pii pair <int , int>
#define pll pair <ll , ll>
#define fi first
#define se second
#define setp(x) setprecision(x)
#define meme(x,i) memset(x,i,sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define me max_element
const int N = 100005;

void solve() {
	int n;
	cin >> n;
	cout << 2 << endl;
	multiset<int> s;
	f(i,1,n+1){
		s.insert(i);
	}
	while(s.size()>1){
		auto it1=--s.end();
		auto it2=it1;
		it2--;
		int x=*it1,y=*it2;
		cout << x << " " << y << endl;
		s.erase(it1);
		s.erase(it2);
		s.insert((x+y+1)/2);
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
    for(int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}
