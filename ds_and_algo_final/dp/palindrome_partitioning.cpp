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
string s ;
int dp[100][100] ;

bool is_palindrome(int i , int j){
	while(i<j){
		if(s[i]!=s[j]) return false ;
		i++ , j-- ;
	}
	
	return true ;
}

int palindrome_part(int i, int j){
	
	if(dp[i][j]!=-1) return dp[i][j] ;
	
	if(i>=j) return 0 ;
	
	if(is_palindrome(i,j)) return 0 ;
	
	int val = inf ;
	
	for(int k=i ; k<j ; k++){
		int left , right ;
		
		if(dp[i][k]!=-1) left = dp[i][k] ;
		else left = palindrome_part(i,k);
		
		if(dp[k+1][j]!=-1) right = dp[k+1][j] ;
		else right = palindrome_part(k+1 , j);
		
		val = min(val , 1 + left + right );
	}
	
	return dp[i][j] =val ;
}

void solve()
{
	 memset(dp , -1 , sizeof dp);
	 cin>>s ;
	 debug(palindrome_part(0 , s.length() - 1 ));
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
