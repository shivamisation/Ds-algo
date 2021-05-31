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
const int maxx  = 1000 ; 
vector<int> dp(maxx,-1) ; 


// recursive solution 
int catlan(int n){
	if(n<2) return 1 ;
	else if(dp[n]!=-1) return dp[n] ;
	int res = 0 ; 
	
	for(int i=0 ; i<n ; i++){
		res+= catlan(i)*catlan(n-i-1); // one might use modulo here and other things 
	}
	return dp[n] = res ; 
}

// iterative soulutioln 
int cat(int n){
	vector<int> catt(n+1,0);
	catt[0] = 1 , catt[1 ] =1 ; 
	
	for(int i=2 ; i<=n ; i++){
		for(int j=0 ; j<i ; j++){
			catt[i]+= catt[j]*catt[i-j-1] ; // one might use the mod and all here
		}
	}
	
	return catt[n] ; 
}

void solve()
{
	int n ; cin>>n ; 
	debug(catlan(n));
	
 
 
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
