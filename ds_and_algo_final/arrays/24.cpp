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

// does not maintains the order of appearance 

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	// here we need to bring all the negative values to the last 
	
	int i=0 , j = n-1 ; 
	while(i<j){
		if(a[i]>=0) i++ ; 
		else {
			swap(a[i],a[j]);
			j-- ; 
		}
	}
	
	//we are finding the leftmost index of negative element
	j = n-1 ; 
	while(a[j]<0) j-- ; 
	j++ ; 
	
	
	//now we need the place them alternatively ; 
	
	i = 0 ;
	
	while(i<n && j<n){
		swap(a[i] , a[j]);
		j++ ; 
		i+=2 ; 
	}
	
	debug(a);
	
	
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
