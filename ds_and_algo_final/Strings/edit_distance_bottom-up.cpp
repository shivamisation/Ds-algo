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
	string a , b ; cin>>a>>b ; 
	
	int n = a.size() , m = b.size();
	
	vector<vector<int>> dp(n+1 , vector<int>(m+1));
	
	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=m ; j++){
			if(i==0) dp[i][j] = j ; 
			else if (j==0) dp[i][j] = i ; 
			
			else if (a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1] ;
			}
			
			else {
				dp[i][j] = 1 + min({dp[i][j-1] , dp[i-1][j] , dp[i-1][j-1]});
			}
		}
	}
	
	cout<<dp[n][m] ; 
	
	
	// for better space complexity use i%2 and (i-1)%2 ..this will take the complexity to 
	//O(n*m) to O(min(n , m)) 
	
	
	// and also try to retrace the path of dp by using the dp matrix.. 
	
	
	
	
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
