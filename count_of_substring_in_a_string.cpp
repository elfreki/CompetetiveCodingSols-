
//Inshallah , Boys played well..!!
//Saurabh Srivastava//

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back
#define pf push_front
#define mk make_pair
#define f(i,j,n) for(int i=j;i<n;i++)
#define r(i,n,j) for(int i=n-1;i>=j;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Test int t;cin>>t;while(t--)
#define mod 1000000007
#define MIN INT_MIN
#define MAX INT_MAX
#define all(container) container.begin() , container.end()
#define rall(container) container.rbegin() , container.rend()
#define sz(container) (int)container.size()
#define pii pair <int , int>
#define fi first
#define se second
#define setp(x) setprecision(x)
#define maxn 1000005
int n;
string s,ss;
ll power(ll x,ll y){
    x%=mod;
    y%=mod;
    ll var=x,ans=1;
    while(y){
        if(y&1)
            ans=((ans%mod)*(var%mod))%mod;
        var=((var%mod)*(var%mod))%mod;
        y=y>>1;
    }
    return ans;
}

void count_sort(vector<int> &p,vector<int> &c){
    int n=sz(p);
    vector<int> cnt(n) , pos(n);
    f(i,0,n)
        cnt[c[i]]++;
    pos[0]=0;
    f(i,1,n)
        pos[i] = pos[i-1] + cnt[i-1];
    vector<int> p_new(n);
    f(i,0,n){
        p_new[pos[c[p[i]]]++] = p[i];
    }
    p=p_new;
}
void solve(){
    cin >> s;
    s+="$";
    n=s.length();
    vector<int> p(n),c(n);
    vector<pair<char,int>> vp;
    f(i,0,n)
        vp.pb({s[i],i});
    sort(all(vp));
    f(i,0,n) p[i]=vp[i].se;
    c[p[0]]=0;
    f(i,1,n){
        if(vp[i].fi==vp[i-1].fi)
            c[p[i]]=c[p[i-1]];
        else
            c[p[i]]=c[p[i-1]]+1;
    }                    
    int k=0;
    while((1<<k)<n){
        f(i,0,n){
            p[i]=(p[i]-(1<<k)+n)%n;
        }
        count_sort(p,c);
        vector<int> c_new(n);
        c_new[p[0]]=0;
        f(i,1,n){
            pii prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pii now={c[p[i]],c[(p[i]+(1<<k))%n]};
            if(prev==now)
                c_new[p[i]]=c_new[p[i-1]];
            else
                c_new[p[i]]=c_new[p[i-1]]+1;
        }
        c=c_new;
        k++;
    }
    int q;
    cin >> q;
    while(q--){
        cin >> ss;
        int m=sz(ss);
        if(m>=n){
            cout << "0\n";
            continue;
        }
        int low=1,high=n-1;
        bool flag=false;
        while(low<=high){
            int mid=(low+high)/2;
            f(i,0,m){
                if(ss[i]<s[i+p[mid]]){
                    high=mid-1;
                    break;
                }
                else if(ss[i]>s[i+p[mid]]){
                    low=mid+1;
                    break;
                }
                else if(i==m-1){
                    flag=true;
                    high=mid-1;
                }
                else if(i+p[mid]==n-2){
                    low=mid+1;
                    break;
                }
            }
        } 
        if(flag){
            ll ans=low;
            low=1,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                f(i,0,m){
                    if(ss[i]<s[i+p[mid]]){
                        high=mid-1;
                        break;
                    }
                    else if(ss[i]>s[i+p[mid]]){
                        low=mid+1;
                        break;
                    }
                    else if(i==m-1){
                        low=mid+1;
                    }
                    else if(i+p[mid]==n-2){
                        low=mid+1;
                        break;
                    }
                }
            }
            cout << high-ans+1 << endl;
        }
        else
            cout << "0\n";
    }
}
int main(){
    fast;   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin >> t;
    while(t--)  solve();
}
