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

bool check(vector<ll> a , ll k , ll n){
	map<ll,ll> mp ;
	ll m = a.size();
	for(int i=0 ; i<k ; i++) {
		mp[a[i]]++ ;
	}
	if(mp.size() == n){
		return true; 
	}
	
	for(int i=k ; i<a.size() ; i++){
		mp[a[i]]++ ;
		if(mp[a[i-k]] == 1) mp.erase(a[i-k]);
		else mp[a[i-k]] -- ; 
		
		if(mp.size() == n and (i>=m and i-k<=m-1)) return true ;
	}
	
	return false ;
}


void solve()
{
	ll m , n; cin>>n>>m ;
	vector<ll> a(2*m);
	for(int i=0 ; i<m ; i++) cin>>a[i] ;
	
	map<ll,ll> mp ;
	ll ans = inf ;
	
	for(int i=0 ; i<n ; i++){
		mp[a[i]]++ ;
		if(mp.size() == n){
			ans = min(ans , 1ll*(i+1));
			break; 
		}
	}
	
	mp.clear();
	for(int j=m-1 ; j>=0 ; j--){
		mp[a[j]]++ ;
		if(mp.size()==n){
			ans = min(ans , m-j);
			break ;
		}
	}
	
	mp.clear();
	
	for(int i=m ; i<2*m ; i++) a[i] = a[i-m] ;
	
	ll lo = 1 , hi = m ;
	
	while(lo<=hi){
		ll mid = (lo+hi)/2; 
		if(check(a , mid , n)){
			ans = min(ans , mid);
			hi = mid -1 ;
		}
		else lo = mid+1 ;
	}
	
	cout<<ans<<"\n" ;
	

	
	
	

}

int main()
{
	speed(); 
    int T = 1;
    cin >> T;
    while (T--){
    solve();
}
}
