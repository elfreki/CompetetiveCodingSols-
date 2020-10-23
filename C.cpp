#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
 
void read_file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int main(){
	read_file();
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0 ; i < (int)s.length() ; ++i){
			if(!st.empty() && st.top() == 'A' && s[i] == 'B'){
				st.pop();
				continue;
			}
			else if(!st.empty() && st.top() == 'B' && s[i] == 'B'){
				st.pop();
				continue;
			}
			st.push(s[i]);
		}
		cout << (int)st.size() << '\n';
	}
	return 0;
}
