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

int lis(vector<int> a){
	
	int n = a.size();
	
	vector<int> dp(n+1 , inf);
	
	dp[0] = zer ;
	
	for(int i=0 ; i<n ; i++){
		int id = upper_bound(dp.begin() , dp.end() , a[i]) - dp.begin();
		if(a[i]>dp[id-1] and a[i]<dp[id]) dp[id] = a[i] ;
	}
	
	int ans = 0 ;
	for(int i=n ; i>=0 ; i--){
		if(dp[i]!=inf) {
			ans = i ;
			break ;
		}
	}
	
	debug(dp);
	
	return ans ;
	
	
}

void solve()
{
	vector<int> a =  { 10, 22, 9, 33, 21, 50, 41, 60 } ;
	cout<<lis(a);
	
 
 
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
