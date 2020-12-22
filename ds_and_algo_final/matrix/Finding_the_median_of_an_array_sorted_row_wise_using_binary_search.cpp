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

int search(vector<int> a , int val){
	int n = a.size()-1, ans =-1 ; 
	int hi = n, lo = 0 ; 
	while(hi>=lo){
		int mid = lo + (hi- lo)/2 ; 
		if(a[mid]>val) hi = mid-1 ; 
		else {
			ans = mid ; 
			lo = mid +1; 
		}
	}
	if(ans==-1) return 0 ; 
	else return ans +1;
}

void solve()
{
	int n , m ; cin>>n>>m ; 
	vector<vector<int>> a(n, vector<int>(m));
	
	for(auto &it : a){
		for(auto &its : it) cin>>its ; 
	}
	 
	int target = (n*m+1)/2 , lo = inf, hi = zer , ans = 0; 
	
	for(int i=0 ; i<n ; i++){
		lo = min(lo , a[i][0]);
		hi = max(hi , a[i][m-1]);
	}
	
	while(lo<=hi){
		int mid = lo + (hi-lo)/2 ; 
		int cnt =0 ;
		
		for(int i=0 ; i<n ; i++){
			cnt+= search(a[i] , mid);
		}
		
		if(cnt<target) lo = mid+1 ; 
		else {
			ans = mid ; 
			hi = mid-1 ; 
		}
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
