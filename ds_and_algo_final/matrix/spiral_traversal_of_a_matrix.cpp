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

// Printing the spiral traversal of a matrix 

void spiral(vector<vector<int>> a , int i , int j , int m , int n){
	
	if(i>=m or j>=n) return ; 
	
	for(int p = j ; p<n ; p++) {
		cout<<a[i][p]<<" " ; 
	}
	
	for(int p = i+1 ; p<m ; p++){
		cout<<a[p][n-1]<<" " ;
	}
	
	if((m-1)!=i){
		for(int p = n-2 ; p>=j ; p--){
			cout<<a[m-1][p]<<" ";
		}
	}
	
	if((n-1)!=j){
		for(int p = m-2 ; p>i ; p--){
			cout<<a[p][j]<<" " ; 
		}
	}
	
	spiral(a , i+1 , j+1 , m-1 , n-1);
}



void solve()
{
	
	int n , m ; cin>>n>>m ; 
	
	vector<vector<int>> a(m , vector<int> (n));
	
	for(auto &it : a){
		for(auto &its : it){
			cin>>its ; 
		}
	}
	
	spiral(a , 0 , 0 , m , n);
	
	
	
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
