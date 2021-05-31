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

// in order for the space optimised approach we can use the % approach , just replace 
// every i or any bracket of i with ()%2

int lcs(string a, string b,int n, int m){
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + (dp[i-1][j-1]);
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	
	return dp[n][m] ;

}

void solve()
{
	string a = "hala" , b = "hlal" ; 
	cout<<lcs(a,b,a.size() , b.size());
	
	string s = "" ;
	
	int i = a.size() , j = b.size() ;
	
	while(i>0 and j>0){
		if(a[i-1]==b[j-1]){
			s+=a[i-1] ;
			i-- , j-- ; 
		}
		
		else if(dp[i-1][j] > dp[i][j-1]) i-- ;
		else j-- ;
	}
	
	nl;
	
	
	reverse(s.begin() , s.end());
	 
	cout<<s ;
	
	

	
	
 
 
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
