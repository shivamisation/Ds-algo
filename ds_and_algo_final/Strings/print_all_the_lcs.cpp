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
const int N = 1001 ; 
int dp[N][N] ;
//int n , m ; 
	
	// we'll find all the lcs 
	
	
	
	
int lcs(string a , string b ){
	
	int n = a.size() , m = b.size();
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ; 
			else {
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}
	
	return dp[n][m] ; 
	
}


set<string> findlcs(string a , string b , int n , int m){
	
	set<string> s ; 
	
	if(n==0 or m==0){
		//obviously then there are no strings left 
		s.insert("");
		return s ; 
	}
	
	if(a[n-1]==b[m-1]){
		
		set<string> temp = findlcs(a, b , n-1 , m-1);
		
		// now add this letter in all the subsequences that we found ... 
		
		for(auto str : temp){
			s.insert(str + a[n-1]);
		}
		
	}
	
	
	else {
		if(dp[n-1][m] >= dp[n][m-1]){
			s = findlcs(a , b , n-1 , m);
		}
		
		if(dp[n][m-1] >= dp[n-1][m]){
			set<string> tmp = findlcs(a , b , n , m-1);
			
			s.insert(tmp.begin() , tmp.end());
		}
	}
	
	return s ; 
	
}

void solve()
{
	string a , b ; cin>>a>>b ; 
	memset(dp , 0 , sizeof dp);
	//n= a.size() , m= b.size();
	
	cout<<lcs(a , b);
	
	debug(findlcs(a , b , a.size() , b.size()));
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
