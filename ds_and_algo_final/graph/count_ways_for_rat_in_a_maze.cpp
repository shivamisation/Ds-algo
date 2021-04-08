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

const int N = 4 ;
vector<int>dx = {0 , 1 , 0 , -1} ;
vector<int>dy = {-1 , 0 , 1 , 0} ;
int cnt = 0 ; 

bool check(vector<vector<int>> maze , int x , int y){
	 return (x>=0 and x<N and y>=0 and y<N and maze[x][y]==1) ;
}

void solve_maze(vector<vector<int>>& maze , int x , int y){
	
	for(auto &it : maze){
		for(auto &in_it : it){
			if(in_it==0) in_it  =-1 ; 
			else in_it = 0 ; 
		}
	}
	
	for(int i=0 ; i<N ; i++){
		if(maze[i][0] == 0){
			maze[i][0] = 1 ; 
		}
		else break ;
	}
	
	for(int i=0 ; i<N ; i++){
		if(maze[0][i] == 0){
			maze[0][i] = 1 ; 
		}
		else break ; 
	}
	
	for(int i=1 ; i<N ; i++){
		for(int j=1 ; j<N ; j++){
			if(maze[i][j]==-1) continue ;
			if(maze[i-1][j] >0) maze[i][j]+=maze[i-1][j] ;
			if(maze[i][j-1] >0) maze[i][j]+=maze[i][j-1] ;
		}
	}
	
	debug(maze[N-1][N-1]);

}


void solve()
{
	vector<vector<int>> maze ; 
		maze =        { { 1, 0, 0, 0 }, 
                    { 1, 1, 0, 1 }, 
                    { 0, 1, 0, 0 }, 
                    { 1, 1, 1, 1 } }; 
                    
     solve_maze(maze , 0 , 0);
     debug(cnt);
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
