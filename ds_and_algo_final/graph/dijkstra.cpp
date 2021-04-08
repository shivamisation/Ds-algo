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
const int N = 100 ; 
vector<pair<int,int>> adj[N] ; 
vector<bool> vis(N) ; 

/// HOW IT WORKS.... JUST THINK IT BRUH 

void dijkstra(int s , vector<int>& dis , vector<int> &p){
	int n = N ;
	
	dis[s] = 0 ;
	
	for(int i=0 ; i<n ; i++){
		int v = -1; // represents the edge with mininum value of v
		
		for(int j=0 ; j<n ; j++){
			if(!vis[j] and (v==-1 or dis[j]<dis[v])) v = j ;
		}
		
		// Now we have found the minimum value of such an edge which is at minimum distance from it ; 
		
		if(dis[v]==inf) break ; // we are almost done 
		
		vis[v] = true ; // mark it as visited 
		
		for(auto edge : adj[v]){
			int to = edge.first ;
			int len = edge.second ; 
			
			if(dis[v]+len <dis[to]){
				dis[to] = dis[v] + len;
				p[to] = v ;
			}
		}
	}	
}

vector<int> restore_path(vector<int> p , int t , int s){
	vector<int> path ;
	
	for(int v = t ; v!=s ; v=p[v]) path.push_back(v);
	
	path.push_back(s);
	
	reverse(path.begin() , path.end());
	
	return path ;
}

struct edge
{
	int a , b , cost ;
	
};

int n , m , v ; 
vector<edge> e ; 


void solve()
{
	cin>>n>>m ;
	
	for(int i=0 ; i<m ; i++){
		int a , b , c ; 
		cin>>a>>b>>c ; 
		edge x ;
		x.a = a ;
		x.b = b ;
		x.cost = c ;
		e.push_back(x);
	}
	
    vector<int> d (n, inf);
    d[v] = 0;
    vector<int> p (n, -1);

    for (;;)
    {
        bool any = false;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < inf)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)  break;
    }
    
    int t = 4 ; 

    if (d[t] == inf)
        cout << "No path from " << v << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }

	/*
	 * 
	 *sample test 
8 1
1 2 3 
1 3 1 
2 3 7 
3 4 2 
2 4 16
1 4 7 
1 5 1
5 4 3 

	*/
	
	
	
	
	
	
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
