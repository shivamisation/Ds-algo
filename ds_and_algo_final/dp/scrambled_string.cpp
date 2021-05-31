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

unordered_map<string , bool > dp ;

bool is_scramble(string a, string b){
	
	string temp = a ;
	temp+=' ';
	temp+=b ;
	
	if(dp.find(temp)!=dp.end()) return dp[temp] ;
	
	
	if(a.length() != b.length()) return false ;
	
	int n = a.length();
	if(n==0) return true ;
	
	if(a==b) return true ;
	
	// check for anagram condition 
	string temp_a = a , temp_b = b ;
	sort(temp_a.begin() , temp_a.end());
	sort(temp_b.begin() , temp_b.end());
	
	if(temp_a!=temp_b) return false ;
	
	bool flag = false ;
	
	for(int i=1 ; i<n ; i++){
		
		if(is_scramble(a.substr(0,i) , b.substr(0,i)) and
			is_scramble(a.substr(i,n-i) , b.substr(i,n-i))) {
			flag = true ;
		}
		
		if(is_scramble(a.substr(0,i) , b.substr(n-i,i))   and
			is_scramble(a.substr(i,n-i) , b.substr(0,n-i))) {
			
			flag = true ;
		}
	}
	
	return dp[temp] = flag ;
}

void solve()
{
	string a , b ; 
	a = "coder" ,b = "ocred" ;
	
	debug(is_scramble(a ,b));
	
 
 
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
