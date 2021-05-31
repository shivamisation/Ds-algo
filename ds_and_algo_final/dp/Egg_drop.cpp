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
int dp[1000][1000] ;
ll cnt = 0 ; 

int Egg_drop(int n , int f){
	
	if(dp[n][f]!=-1) return dp[n][f] ;
	
	cnt++ ;
	
	//debug(n,f);
	
	if(f==1 or f==0) return f ; // no floor or 1 floor ;
	
	if(n==1) return f ; // only one egg so worst case is drop from every floor 
	
	int mn = inf , temp ;
	
	for(int k=1 ; k<=f ; k++){
		temp = 1 + max(Egg_drop(n-1 , k-1) , Egg_drop(n,f-k));
		mn = min(mn , temp);
	}
	
	return  dp[n][f] = mn ; 
}

void solve()
{
	memset(dp , -1 , sizeof dp);
	int n , f ;
	n = 6 , f = 100 ;
	
	debug(Egg_drop(n,f));
	
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
