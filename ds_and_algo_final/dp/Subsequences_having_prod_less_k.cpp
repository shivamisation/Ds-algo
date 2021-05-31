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


void solve()
{
	
	vector<int> a = {1 , 2 , 3 , 4} ;
	
	int n = a.size();
	int k = 10 ;
	
	vector<vector<int>> dp(k+1 , vector<int>(n+1 , 0));
	
	for(int i=1 ; i<=k ; i++){
		for(int j=1 ; j<=n ; j++){
			dp[i][j] = dp[i][j-1] ;
			if(a[j-1]<=i and a[j-1]>0) dp[i][j]+= 1 + dp[i/a[j-1]][j-1] ;
		}
	}
	
	cout<<dp[k][n] ;
 
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
