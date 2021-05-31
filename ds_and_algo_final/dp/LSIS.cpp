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

int lsis(vector<int> a){
	
	int n = a.size();
	
	vector<int> dp(n );
	
	for(int i=0 ; i<n ; i++){
		dp[i] = a[i] ;
	}
	
	vector<int> par(n);
	for(int i=0 ; i<n ; i++) par[i] = i ;
	
	for(int i=1 ; i<n ; i++){
		for(int j=0 ; j<i ; j++){
			if(a[j]<a[i] and dp[j] + a[i] > dp[i]){
				dp[i] = dp[j] + a[i];
				par[i] = j ;
			}
		}
	}
	
	int ans = zer ;
	
	int ind = 0 ;
	
	for(int i=0 ; i<n ; i++){
		if(dp[i]>ans){
			ans = dp[i] ;
			ind = i ;
		}
	}
	
	vector<int> list ;
	
	while(true){
		list.push_back(a[ind]);
		if(par[ind]==ind) break;
		else ind = par[ind] ;
	}
	
	reverse(list.begin() , list.end());
	debug(list);

	
	return ans ;
	
}

void solve()
{
	vector<int> a =   {1, 101, 2, 3, 100, 4, 5};
	cout<<lsis(a);
	
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
