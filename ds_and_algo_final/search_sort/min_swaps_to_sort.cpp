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

// This can be easily done by visualizing the problem as a graph. We will
 //have n nodes and an edge directed from node i
// to node j if the element at i’th index must be present at j’th index 
//in the sorted array. 

void solve()
{
	
	int n; cin>>n ; 
	vector<int> a(n);
	
	for(auto &it : a) cin>>it ; 
	
	vector<pair<int,int>>  pos(n);
	
	for(int i=0 ; i<n ; i++){
		pos[i].first = a[i] ;
		pos[i].second = i ;
	}
	
	sort(pos.begin() , pos.end());
	
	vector<bool> vis(n , false);
	
	int ans = 0 ; 
	
	for(int i=0 ; i<n ; i++){
		
		if(vis[i] or pos[i].second == i) continue ; 
		
		int cycle_size = 0 ;
		int j= i ; 
		
		while(!vis[j]){
			vis[j] = i ; 
			
			j = pos[j].second ; 
			
			cycle_size++ ; 
		}
		
		if(cycle_size) ans+= cycle_size - 1 ; 
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
 
