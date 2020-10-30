#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
//#define int long long int
#define v1 vector<int>
#define mapp map<int,int>
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int modulo=1000000007;
#define test int t;cin>>t;while(t--)
#define f(i,j,n) for(int i=j;i<n;i++)
#define r(i,j,n) for(int i=j-1;i>=n;i--)
#define minn INT_MIN
#define maxx INT_MAX
#define all(container) container.begin() , container.end()
#define sz(container) (int)container.size()
#define pii pair <int , int>
#define pll pair <long long int , long long int>
#define setp(x) setprecision(x)
int power(int a,int n){
    a%=modulo;
    n%=modulo;
    int var=a,ans=1;
    while(n){
        if(n&1)
            ans=((ans%modulo)*(var%modulo))%modulo;
        var=((var%modulo)*(var%modulo))%modulo;
        n=n>>1;
    }
    return ans;
}
// ------------------------------------Tempote End------------------------------ //
int N = 100005;
int n,m;
int vis[105][105] = {0};

void solve(){
    int x,y;
    cin>>n>>m>>x>>y;
    stack<pii> qp;
	qp.push({x, y});
	while (!qp.empty()) {
		pii p = qp.top();
		qp.pop();
		if (vis[p.first][p.second])
			continue;
		cout << p.first << " " << p.second<< endl;
		vis[p.first][p.second] = 1;
		if (1 < p.first && !vis[p.first - 1][p.second])
			qp.push({p.first - 1, p.second});
		if (p.second< m && !vis[p.first][p.second+ 1])
			qp.push({p.first, p.second+ 1});
		if (1 < p.second&& !vis[p.first][p.second- 1])
			qp.push({p.first, p.second- 1});
		if (p.first < n && !vis[p.first + 1][p.second])
			qp.push({p.first + 1, p.second});
	}
}

signed main(){
	fast;
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt",
    #endif
    //test
     solve();
}

			
	
 
