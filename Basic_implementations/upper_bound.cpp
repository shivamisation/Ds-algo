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

//upper bound gives you the index of the largest element which is lesser than or equal to 
//the target . 

//Lower bound gives you the index of the lowest number which is greater than the desired 
//target . 

int lower(vector<int> a , int x ){
	int hi = a.size() - 1 , lo = 0 ;
	int ans =0 ; 
	
	while(lo<=hi){
		int mid = (lo+hi)/2 ; 
		debug(hi , lo , mid , a[mid]);
		if(a[mid] > x) hi = mid-1 ; 
		else {
			ans = lo ;
			lo = mid+1; 
		}
	}
	return ans ; 
}

int higher(vector<int> a , int x ){
	int hi = a.size()-1 , lo = 0;
	int ans =0 ;
	
	while(lo<=hi){
		int mid = (lo+hi)/2 ; 
		if(a[mid]>x) {
			ans = mid ; 
			hi = mid-1 ; 
		}
		else lo = mid+1 ; 
	}
	
	return ans ; 
}

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	int x; cin>>x ; 
	
	cout<<lower(a,x);
	
	debug(lower(a, x));
	//debug(higher(a,x));
	
	
	
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
