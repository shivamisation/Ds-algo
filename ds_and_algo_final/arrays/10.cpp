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

//Given an array of N integers and an integer k. It is allowed to modify an element either by increasing or decreasing them by k (only once).



void solve()
{
	
	int n , k ; cin>>n>>k ; 
	
	if(n==1) {
		cout<<0 ; 
		return ; 
	}
	
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	sort(a.begin() , a.end());
	
	int ans = a[n-1] - a[0] ; 
	
	int small = a[0] + k ; 
	int big = a[n-1] -k ; 
	
	if(small > big) swap(small , big);
	
	for(int i=1 ; i<n-1 ; i++){
		int subtract = a[i] - k ; 
		int add = a[i]+k ; 
		
		
		
		if(subtract >=small || add<=big) continue ; 
		
		if(big - subtract <= add - small) small = subtract ; 
		else big=add ;
		
		ans = min(ans , big - small ); 
	}
	
	debug(ans);
	
	
	
	
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
