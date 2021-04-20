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
const int mod = 1e7 + 9 ; 
void speed() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
const ll N = 1e4 ; 
vector<ll> is_prime(N ,1) ;

void seive(){
	for(ll i = 4 ; i<N ; i+=2) is_prime[i] = 0 ; 
	is_prime[1] = 0 ; 
	
	for(ll i=3 ; i*i < N ; i++){
		if(is_prime[i]){
			for(ll j = i*i ; j<N ; j+=i){
				is_prime[j] = false ; 
			}
		}
	}
}


void solve()
{
	seive(); 
	
	vector<ll> primes ; 
	for(int i=1 ; i<N ; i++) if(is_prime[i]) primes.push_back(i);
	
	int n ; cin>> n ; 
	ll lcm = 1; 
	
	//debug(primes);
	
	for(int i=0 ; i<(int)primes.size() and primes[i]<=n ; i++){
		int val = primes[i] ; 
		while(val*primes[i] <= n) val*=primes[i] ;
		
		lcm*=val ;
		lcm%=mod ; 
	}
	
	debug(lcm);
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
