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
const int N = 1000 ; 
vector<int> adj[N] ;
vector<int> vis(N , 0) ;
bool check = 0 ; 
vector<int> par(N , -1) ;
vector<int> traversal ; 
int cycle_start , cycle_end ; 


bool dfs(int node){
	vis[node] = 1 ;
	traversal.push_back(node);
	for(auto child : adj[node]){
		if(vis[child] == 0){
			par[child] = node ; 
			if(dfs(child)) return true ; 
		}
		
		else if(vis[child] == 1){
			check = true ;  
			cycle_start = child ;
			cycle_end = node ; 
			return true ; 
		}
	}
	
	vis[node] = 2 ; 
	return false ; 
}

void solve()
{
	int e ; cin>>e ; 
	int k = e ; 
	while(k--){
		int a , b ; cin>>a>>b ; 
		adj[a].push_back(b);
	}
	
	
	
	for(int v = 0 ; v<e ; v++){
		if(vis[v]==0 and dfs(v)) break ; 
	}
	
	if(check){
		vector<int> cycle ;
		cycle.push_back(cycle_start);
		for(int v = cycle_end ; v!=cycle_start ; v = par[v]) cycle.push_back(v);
		cycle.push_back(cycle_start);
		reverse(cycle.begin() , cycle.end());
		debug(cycle);
	}
	
	debug(check);
	debug(traversal);
	
	
	
	
	
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
