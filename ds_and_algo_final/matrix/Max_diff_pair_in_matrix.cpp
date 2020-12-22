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

//Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

int max_diff(vector<vector<int>> a){
	int n = a.size();
	int max_val = zer ; 
	vector<vector<int>> max_a(n , vector<int>(n));
	
	max_a[n-1][n-1] = a[n-1][n-1] ; 
	
	int maxv = a[n-1][n-1] ; 
	
	for(int r=n-2 ; r>=0 ; r--){
		maxv = max(maxv , a[r][n-1]);
		max_a[r][n-1]=maxv ; 
	}
	
	maxv = a[n-1][n-1] ;
	
	for(int c=n-2 ; c>=0 ; c-- ){
		maxv = max(maxv , a[n-1][c]);
		max_a[n-1][c] = maxv ;
	}
	
	
	for(int r = n-2 ; r>=0 ; r--){
		for(int c = n-2 ; c>=0 ; c--){
			
			max_val = max(max_val , max_a[r+1][c+1] - a[r][c]);
			max_a[r][c] = max({a[r][c] , max_a[r][c+1] , max_a[r+1][c]}) ; 
		}
	}
	
	return max_val ; 
	
}

void solve()
{
	//int n ; cin>>n ; 
	vector<vector<int>> a;
	
	//for(auto &it : a){
		//for(auto &its : it) cin>>its ; 
	//}
	
	a = { 
                      { 1, 2, -1, -4, -20 }, 
                      { -8, -3, 4, 2, 1 }, 
                      { 3, 8, 6, 1, 3 }, 
                      { -4, -1, 1, 7, -6 }, 
                      { 0, -4, 10, -5, 1 } 
                    }; 
	
	debug(max_diff(a));
	
	
	
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
