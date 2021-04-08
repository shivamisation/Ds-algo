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

void solve()
{
	
	vector<vector<int>> matrix ; // this is an adjacency matrix in which the value of the 
								// matrix[i][j] is the edge weight between the nodes i and j
	  int n = matrix.size() ;
	    int INF = INT_MAX ; 
	    
	    for(int k=0 ; k<n ; k++){
	        for(int i=0 ; i<n ; i++){
	            for(int j=0 ; j<n ; j++){
	                bool a = matrix[i][k] < INF and matrix[k][j]<INF and (matrix[i][k]+matrix[k][j] < INF) ; 
	                bool b = matrix[i][k]!=-1 and matrix[k][j]!=-1 and matrix[i][j]!=-1 ; 
	                if(a and b){
	                    matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]) ; 
	                }
	            }
	        }
	    }
	    
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<n ; j++){
	            if(matrix[i][j]==INF) matrix[i][j] = -1 ; 
	        }
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
