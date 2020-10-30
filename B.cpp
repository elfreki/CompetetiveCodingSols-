#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       if(k>=n) cout<<1<<endl;
       else{
       int res=n;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int s= min(i,n/i);
                int r=n/s;
                if(r<=k) res=min(s,res);
                else if(s<=k) res=min(r,res);
            }
        }
        cout<<res<<endl;
       }
    }
}
