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
// here dp(i,j) is the maximum profit that can be gained such that I can do a maximum of 
//i transactions on the jth day . 
// the formula is dp[i][j] = max(dp[i][j-1] , price[j] + max_in_the_range(0,m-1){profit[i-1][m]-price[m]} 
// we can further decrease the time complexity by storing that max_diff. 
// the space complexity can be further reduced by using mod 2 . 
void solve()
{
	int n,k; cin>>n>>k ; 
	
	vector<int> price(n);
	for(auto &it : price) cin>>it ; 
	
	vector<vector<int>> dp(k+1 , vector<int>(n+1));
	
	for(int i = 1 ; i<=k ; i++)
	{
		int prev_diff = zer ; 
		for(int j = 1 ; j<n ; j++)
		{
			prev_diff = max(prev_diff , dp[(i-1)][j-1] - price[j-1]);
			dp[i][j] = max(dp[i][j-1] , prev_diff + price[j]);
		}
	}
	
	debug(dp[k][n-1]);
	
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
