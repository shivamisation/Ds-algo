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
ll P , T ; 
const ll MAX = 101 ; 
const ll p = 31 ; 
const ll m = 1e9 + 9 ;

void solve()
{
	
	string text , pat ; cin>>text>>pat ; 
	P = pat.length() , T = text.length();
	
	// precomputing the powers of the base value , which in case is p 
	
	vector<ll> p_pow(max(P ,T));
	
	p_pow[0] = 1 ; 
	
	for(int i=1 ; i<(int)p_pow.size() ; i++) p_pow[i] = (p_pow[i-1]*p) % m ;
	
	// calculating the has value for the text 
	
	vector<ll> hash(T+1 , 0);
	for(int i=0 ; i<T ; i++){
		hash[i+1] = (hash[i] + (text[i] - 'a' + 1) * p_pow[i])%m ;
		
		// hash is something like 
		// s[0] + s[0]*p + s[1]*p^2 ....
	}
	
	ll hash_pat = 0 ;
	for(int i=0 ; i<P ; i++){
		hash_pat = (hash_pat + (pat[i] - 'a' +1) * p_pow[i])%m ;
	}
	
	vector<int> occurences ; 
	
	for(int i=0 ; i+P-1 <T ; i++){
		ll curr_hash = (hash[i+P] + m - hash[i]) % m ; 
		if(curr_hash  == hash_pat*p_pow[i]%m) occurences.push_back(i);
	}
	
	//return occurences ; 
	debug(occurences);
	
	
	
	

	
	
	
}

int main()
{
	speed(); 
    int Te = 1;
    //cin >> T;
    while (Te--){
    solve();
}
}
