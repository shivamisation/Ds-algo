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
vector<int> adj[N];
vector<int> vis(N) ;
vector<int> parent(N) ;
int cycle_start , cycle_end ; 

bool dfs(int v , int par){
	vis[v] = true ;
	for(int child : adj[v]){
		if(child==par) continue ;
		if(vis[child]){
			cycle_end = v ; 
			cycle_start = child ;
			return true ;
		}
		parent[child] = v ;
		if(dfs(child, parent[child])) return true ; 
	}
	return false ; 
}

void solve()
{
	int e ; cin>>e ; 
	int k = e ; 
	for(auto &it : parent) it = -1 ; 
	cycle_start=-1 ; 
	
	while(k--){
		int a , b ; 
		cin>>a>>b ; 
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=0 ; i<e ; i++){
		if(!vis[i] and dfs(i,parent[i])) break ;
	}
	
	// Here we are just printing the loop found in the array ... 
	if(cycle_start!=-1){
		cout<<"Cycle Found !\n";
		vector<int> cycle ;
		cycle.push_back(cycle_start);
		for(int v = cycle_end ; v!=cycle_start ; v = parent[v]) cycle.push_back(v);
		cycle.push_back(cycle_start);
		reverse(cycle.begin() , cycle.end());
		
		for(auto it : cycle) cout<<it<<" " ;
		nl ; 
	}
	
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
