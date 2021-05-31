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

vector<vector<int>> a ;
vector<vector<int>> t ;
vector<int> e;
vector<int> x ;
int n ;
int dp[100][2] ;

int rec(int ind , int l){
	
	if(dp[ind][l]!=-1) return dp[ind][l] ;
	
	if(ind == 0){
	 	 return dp[ind][l] = e[l] + a[l][0] ;
	}
	
	return dp[ind][l] = min(rec(ind-1,l) + a[l][ind] , rec(ind-1,l^1) + a[l][ind] + t[l^1][ind]);
}

void solve()
{
	memset(dp , -1 , sizeof dp);
	a = {{4,5,3,2},
		 {2,10,1,4}} ;
	
	t = {{0,7,4,5},
		 {0,9,2,8}} ;
		 
	e = {10,12} ;
	x = {18,7} ;
	
	n = a[0].size();
	
	debug(min(rec(n-1,1) + x[1] , rec(n-1,0) + x[0]));
	
	
	
	

	
	
	
 
 
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
