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

// counting all palindromic subsequences 

void solve()
{
	
	string s ; cin>>s ; 
	
	int n = s.size();
	
	vector<vector<int>> dp(n+1 , vector<int>(n+1));
	
	for(int i=0 ; i<n ; i++) dp[i][i] = 1 ; 
	
	for(int l=2 ; l<=n ; l++){
		for(int i=0 ; i<n ; i++){
			
			int k = i+l-1 ; 
			if(k>=n) continue; 
			
			if(s[i]==s[k]){
				dp[i][k] = dp[i][k-1] + dp[i+1][k] + 1 ; 
			}
			
			else {
				dp[i][k] = dp[i][k-1] + dp[i+1][k] - dp[i+1][k-1] ; 
			}
		}
	}
	
	
	
	debug(dp[0][n-1]);
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			debug(dp[i][j] , i , j );
		}
	}
	
	
	
	
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
