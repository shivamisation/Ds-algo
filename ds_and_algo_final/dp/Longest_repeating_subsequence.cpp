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
int dp[100][100] ;

string lrs(string a ){
	int n = a.length();
	
	// dp(x,0) and dp(y,0) is zero already for any x and y
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			
			if(a[i-1] == a[j-1] and i!=j) dp[i][j] = 1 + dp[i-1][j-1] ;
			else dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
		
		}
	}
	
	int i = n , j = n ;
	
	string s = "" ;
	
	while(i and j){
		if(dp[i][j] == dp[i-1][j-1] + 1 ) {
			
			s+=a[i-1] ;
			i-- , j-- ;
		}
		else if(dp[i][j] == dp[i-1][j]) i-- ;
		else j-- ;
	}
	
	
	reverse(s.begin() , s.end());
	
	return s ;
}

void solve()
{
	string a = "aabebcdd" ;

	cout<<lrs(a);
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
