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

//make string a equal to string b while performing operation on string a ; 


int edit_distance(string a , string b , int n , int m){
	
	if(n==0) return m ; //insert m characters 
	
	if(m==0) return n ; //delete n characters 
	
	if(dp[n][m]!=-1) return dp[n][m] ; 
	
	if(a[n-1]==b[m-1]){
		return dp[n][m] = edit_distance(a , b , n-1 , m-1); // if they are same we dont need to do.
	}
	
	return dp[n][m] =  1 + min({edit_distance(a , b , n , m-1) , //insert
					edit_distance(a , b , n-1 , m) , //delete
					edit_distance(a , b , n-1 , m-1) ,//replace
		});	
}

void solve()
{
	string a , b ; cin>>a>>b ; 
	
	memset(dp , -1 , sizeof dp);
	
	// This is the edit distance question in which we need to 
	//make the two strings equal in minimum moves ...
	
	//make string a equal to string b ; 
	
	cout<<edit_distance(a , b , a.size() , b.size());
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
