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

void rotate_matrix(vector<vector<int>>& a){
	int n = a.size();
	
	for(int r = 0 ; r<n/2 ; r++){
		for(int c = r ; c<n-r-1 ; c++){
			int temp = a[r][c] ; 
			a[r][c] = a[c][n-1-r] ; // move values from right to top
			a[c][n-1-r] = a[n-1-r][n-1-c] ; //move values from bottom to right 
			a[n-1-c][r] = temp ; 
		}
	}
}

void solve()
{
	int n; cin>>n ; 
	vector<vector<int>> a(n , vector<int> (n));
	
	for(auto &it : a){
		for(auto &its : it) cin>>its ; 
	}
	
	rotate_matrix(a);
	
	for(auto &it : a){
		for(auto &its : it) cout<<its<<" " ; 
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
