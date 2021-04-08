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

int miss(int a[] , int n){
	
	int diff = a[n-1] - a[0] ;
	diff/= n ; 
	
	int hi = n-1 , lo = 0 ; 
	int ans = -1 ; 
	while(hi>=lo){
		int mid = lo + (hi-lo)/2 ; 
		
		if(a[mid+1]-a[mid]!=diff) ans = a[mid]+diff ; 
		
		if(a[mid]-a[mid-1] !=diff) ans = a[mid-1] + diff ; 
		
		if(a[mid] == a[0] + mid*diff) lo = mid+1 ;
		else hi = mid-1 ; 
	}
	
	debug(ans);
	
	return ans ; 
	
	
}

void solve()
{
	 int a[] = {2, 4, 8, 10, 12, 14}; 
	 int n = sizeof(a)/sizeof(a[0]) ;
	 
	 cout<<miss(a, n);

	
	
	
	
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
