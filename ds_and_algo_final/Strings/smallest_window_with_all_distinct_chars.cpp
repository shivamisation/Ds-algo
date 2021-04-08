#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define endl "\n"
#define inf          INT_MAX
#define zer          INT_MIN
#define nl cout<<'\n' ; 
void speed() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
const int MAX = 256 ; 

string findsb(string s){
	
	int n = s.length();
	
	int dist_cnt = 0 ; 
	bool vis[MAX] = {false} ; 
	
	for(int i=0 ; i<n ; i++){
		if(vis[s[i]] == false){
			vis[s[i]] = true ; 
			dist_cnt++ ; 
		}
	}
	
	int start = 0 , start_ind = -1 , min_len = inf ; 
	
	int cnt = 0 ;
	int curr_cnt[MAX] = {0} ;
	
	for(int j = 0 ; j<n ; j++){
		
		curr_cnt[s[j]]++ ; 
		
		if(curr_cnt[s[j]] == 1) cnt++ ; 
		
		if(cnt == dist_cnt){
			
			while(curr_cnt[s[start]] > 1){
				if(curr_cnt[s[start]] > 1) curr_cnt[s[start]] -- ; 
				start++ ; 
			}
			
			int len_window = j-start+1 ; 
			if(min_len >len_window){
				min_len = len_window ; 
				start_ind = start ; 
			}
		}
	}
	
	return s.substr(start_ind , min_len);
}

// The time complexity is O(N) because we just iterate through the string only once .
// using the two pointers ....

void solve()
{
	string s="aabcbcdbca" ;
	
	cout<<findsb(s);
	
	
}

int main()
{
	speed(); 
    int T = 1;
    //cin >> T;
    while (T--){
    solve();
}
}
