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

int dp[100][100][100] ;
int dp_[100][100][100] ;

int lcs3_(string a, string b , string c , int n , int m , int o){
	
	if(n==0 or m==0 or o==0) return 0 ;
	
	if(dp_[n][m][o]!=-1) return dp_[n][m][o] ;
	
	if(a[n-1] == b[m-1] and b[m-1] == c[o-1]) return dp[n][m][o] = 1 + lcs3_(a,b,c,n-1,m-1,o-1);
	
	else {
		return dp[n][m][o] = max({lcs3_(a,b,c,n-1,m,o) , lcs3_(a,b,c,n,m-1,o) , lcs3_(a,b,c,n,m,o-1)});
	}
}

int lcs3(string a, string b , string c ,int  n ,int  m, int o){
	
	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=m ; j++){
			for(int k = 0 ; k<=o ; k++){
				
				if(i==0 or j==0 or k==0) dp[i][j][k] = 0 ; 
				
				else if(a[i-1]==b[j-1] and b[j-1]==c[k-1]){
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1] ;
				}
				
				else {
					dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
				}
			}
		}
	}
	
	return dp[n][m][o] ;
	
	
}

void solve()
{
	string a = "shivam" ;
	string b = "shubham" ;
	string c = "sundaram" ;
	
	memset(dp_,-1 , sizeof dp_);
	
	int n = a.size(),m = b.size() , o = c.size();
	
	cout<<lcs3(a,b,c,n,m,o); // iter
	nl ;
	cout<<lcs3_(a,b,c,n,m,o); // rec
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
