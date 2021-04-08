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

// figure out the length of the longest common substring ...

int lcss(string a , string b , int n , int m){
	
	if(n==0 or m==0) return 0 ; 
	
	int res = 0 ; 
	
	vector<vector<int>> dp(n+1 , vector<int>(m+1));
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			
			if(a[i-1]==b[j-1]){
				
				dp[i][j] = 1 + dp[i-1][j-1] ; 
				
				res = max(res , dp[i][j]);
			}
			
			else dp[i][j] = 0 ; 
			
			debug(i , j , dp[i][j]);
		}
	}
	
	return res ; 
}



void solve()
{
	
	string a , b ; cin>>a>>b ; 
	
	cout<<lcss(a , b , a.size() , b.size());
	
	
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
