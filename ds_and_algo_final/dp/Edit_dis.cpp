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

// Given two string , where you have to change one to the other using the minimum numbner
// of moves 

//	MEMO BY YOURSELF 

/*
 * 
 * insert -> recur for (m,n-1)
 * remove -> recur for (m-1,n)
 * replace -> recur for (m-1 , n-1)
 * 
 * */
 
 int edit_dis(string a , string b , int m , int n){
	 
	 if(m==0) return n ; // those many insertions 
	 if(n==0) return m ;
	 
	 if(a[m-1] == b[n-1]) return edit_dis(a , b , m-1 , n-1);
	 
	 return 1 + min({edit_dis(a,b,m,n-1) , // insert 
		             edit_dis(a,b,m-1,n) , // remove 
		             edit_dis(a,b,m-1,n-1)}); // replace 
 }

void solve()
{
	
	string a = "sunday" ;
	string b = "saturday" ;
	int m = a.size();
	int n = b.size();
	
	debug(edit_dis(a , b , m , n ));
	
	
 
 
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
