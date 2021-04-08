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
int dp[1000][1000] ; 

// dp[i][j] represents the optimal cost the first i indexes with j partitions 

int paint(vector<int> a , int n , int k , vector<int> sum){
	
	if(k==1) return sum[n-1] ; 
	
	if(n==1) return a[0] ;
	
	if(dp[n][k]!=-1) return dp[n][k] ; 
	
	int best = inf ; 
	
	for(int i=1;  i<=n ; i++){
		
		// understand this as 1 | 2 | 3 ......6 | 
		
		best = min(best , max(paint(a , i , k-1 , sum) , sum[n-1] - sum[i-1]));
	}
	
	return dp[n][k] = best ; 
}

void solve()
{
	
	memset(dp , -1 , sizeof dp);
	int n,k ; cin>>n>>k ; 
	
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	vector<int> sum(n);
	
	sum[0] = a[0] ;
	
	for(int i=1 ; i<n ; i++){
		sum[i]+=sum[i-1]+a[i] ; 
	}
	
	cout<<paint(a , n , k , sum);
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
