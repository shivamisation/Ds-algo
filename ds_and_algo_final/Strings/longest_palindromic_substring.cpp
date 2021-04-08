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

// there is a brute force approach for this question
// which requires O(n3) time complexity 

void solve()
{
	string s ; cin>>s ;
	int n = s.length(); 
	
	int max_len = 0 , start =0 ; 
	
	vector<vector<int>> dp(n+1 , vector<int>(n+1));
	
	// we need to fill the dp values for substrings of length 1 and 2 
	
	for(int i=0 ; i<n ; i++) dp[i][i] = 1 ; 
	
	for(int i=0 ; i<n-1 ; i++){
		if(s[i]==s[i+1]){
			dp[i][i+1] = 1 ; 
			start = i ;
			max_len = 2 ; 
		}
	}
	
	for(int sub_str_len=3 ; sub_str_len<=n ; sub_str_len++){
		for(int i=0 ; i+sub_str_len-1 < n ; i++){
			int j = i+sub_str_len-1 ; 
			
			if(dp[i+1][j-1] and s[i]==s[j]) {
				
				dp[i][j] = 1 ; 
				
							
				if(sub_str_len > max_len){
					start = i ; 
					max_len = sub_str_len ; 
				}
			} 
		}
	}
	
	for(int i=start ; i<start+max_len ; i++){
		cout<<s[i] ; 
	}
				
	debug(start , max_len) ;
	
	
	
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
