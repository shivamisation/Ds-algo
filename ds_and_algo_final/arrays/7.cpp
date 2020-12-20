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

//since the two vectors are sorted , use the classic merge technique .
// If not sorted , sort the lesser one and iterate through the larger one and do binary seach on the shorter one , and check if present . 
void solve()
{
	int n ,m ; cin>>n>>m ; 
	vector<int> a(n) , b(m);
	for(auto &it : a) cin>>it ; 
	for(auto &it : b) cin>>it ; 
	vector<int> ans ; 
	
	int i = 0 , j = 0 ; 
	
	while(i<n && j<m)
	{
		if(a[i] < b[j])
		{
			ans.push_back(a[i]);
			i++ ; 

		}
		
		else if(b[j] < a[i])
		{
			ans.push_back(b[j]);
			j++ ; 
		}
		
		else {
			ans.push_back(a[i]);
			i++ , j++ ; 
		}
	}
	
	while(i<n){
		ans.push_back(a[i++]);
	}
	
	while(j<m){
		ans.push_back(b[j++]);
	}
	
	
	debug(ans);
	
	
	
	
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
