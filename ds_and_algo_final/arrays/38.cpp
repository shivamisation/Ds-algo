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
// This is a solution which uses smart array traversal , and uses precalculated values to 
// sovle this problem , all we have to do is to find the largest number in the left side and
// the right side of every index and min(left, right) - a[i] is the water stored in that index
// so we can either precalculate the left and right and say its dp , or use just two variables 
// to do the task ; 

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n); 
	for(auto &it : a) cin>>it ; 
	
	int ans =0 ; 
	int left_max =0 , right_max =0 , hi = n-1 , lo =0 ; 
	
	while(lo<=hi){
		if(a[lo] < a[hi]){
			if(a[lo] > left_max) left_max = a[lo] ; 
			else {
				ans+=left_max - a[lo] ; 
				lo++ ; 
			}
		}
		
		else {
			if(a[hi]>right_max) right_max = a[hi] ; 
			else {
				ans+=right_max - a[hi] ; 
				hi-- ; 
			}
		}
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
