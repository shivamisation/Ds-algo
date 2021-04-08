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
vector<int> parent , rnk ;

void make_set(int v){
	parent[v] = v ; 
	rnk[v] = 0 ; 
}

int find_set(int v){
	if(parent[v]==v) return v ;
	else return parent[v] = find_set(parent[v]);
}

void union_sets(int a , int b){
	
	 a = find_set(a);
	 b = find_set(b);
	
	if(a!=b){
		if(rnk[a]<rnk[b]) swap(a,b);
		
		parent[b] = a ; 
		
		if(rnk[a]==rnk[b]) rnk[a]++ ; 
	}	
}


struct edge{
	int u , v , weight ; 
	
	bool operator <(edge const& other){
		return weight<other.weight ; 
	}
};

void solve()
{
	int e ; cin>>e ;
	int n ; cin>>n ; 
	rnk.resize(n);
	parent.resize(n);
	
	for(int i=0 ; i<=n ; i++){
		make_set(i);
	}
	
	int k =e ; 
	vector<edge> edges ; 
	while(k--){
		int a , b , w ; 
		cin>>a>>b>>w ; 
		edge E ; 
		E.u = a ;
		E.v = b ;
		E.weight = w ; 
		edges.push_back(E);
	}
	
	sort(edges.begin() , edges.end());
	
	vector<edge> result ; 
	int cost = 0 ; 
	
	for(edge ed : edges){
		if(find_set(ed.v)!=find_set(ed.u)){
			cost+=ed.weight ;
			result.push_back(ed);
			union_sets(ed.v, ed.u);
		}
	}
	
	debug(cost);
	
	
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
