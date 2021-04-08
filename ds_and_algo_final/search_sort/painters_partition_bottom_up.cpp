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
	
	memset(dp , 0 , sizeof dp);
	
	for(int i=1 ; i<=n ; i++){
		dp[1][i] = sum[i-1] ;
	}
	
	for(int i=1 ; i<=k ; i++){
		dp[i][1] = a[0] ;
	}
	
	for(int i=2 ; i<=k ; i++){
		for(int j=2 ; j<=n ; j++){
			
			int best = inf ; 
			
			for(int p=1 ; p<=j ; p++){
				best = min(best , max(dp[i-1][p] , sum[j-1] - sum[p-1]));
			}
			
			dp[i][j] = best ; 
		}
	}
	
	return dp[k][n] ; 

}

void solve()
{
	
	//memset(dp , -1 , sizeof dp);
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
