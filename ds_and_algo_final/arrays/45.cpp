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

int lics(int a[] , int n){
	
	unordered_map<int, int> mp ;
	int dp[n] ;
	memset(dp , 0 , sizeof(dp));
	int mx = zer ; 
	
	for(int i=0 ; i<n ; i++){
		
		if(mp.find(a[i] - 1) != mp.end())
		{
			int lst = mp[a[i]-1] - 1 ; 
			
			dp[i] = 1 + dp[lst] ;
		}
		
		else dp[i] = 1 ; 
	
		mp[a[i]] = i+ 1 ; 
		
		mx = max(mx , dp[i]);
	}
	
	return mx ; 


}

void solve()
{
	int a[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<lics(a,n);
	
	
	
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
