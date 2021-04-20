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
int maxx = 1e3 ;
vector<vector<int>> dp(maxx , vector<int> (maxx,-1)) ;

int rec(int n , int k){
	if(k==0 or k==n) return 1 ;
	else if(dp[n][k]!=-1) return dp[n][k] ;
	return dp[n][k] = rec(n-1,k-1) + rec(n-1 ,k);
}

ll iter(int n, int k){
	vector<ll> c(k+1);
	c[0] = 1 ;
	for(int i=1 ; i<=n ; i++){
		for(int j= min(i,k) ; j>0 ; j--){
			c[j] = c[j-1] + c[j] ; 
		}
	}
	
	return c[k] ;
}

void solve()
{
 int n , k ; cin>>n>>k ; 
 
 debug(rec(n,k));
 debug(iter(n,k));	
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
