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

void merge(vector<int> &a1 , vector<int> &a2){
	int m = a1.size(), n = a2.size();
	
	for(int i=n-1 ; i>=0 ; i--){
		int last=a1[m-1] , j ; 
		
		j = m-2 ; 
		while(j>=0 && a1[j] > a2[i]){
			a1[j+1] = a1[j] ;
			j--;
		}
		
		if(j!=m-2 || last > a2[i]){
			a1[j+1] = a2[i] ; 
			a2[i] = last ; 
		}
	}
}

void solve()
{
	int n , m ; cin>>n>>m ; 
	
	vector<int> a1(n) , a2(m);
	
	for(auto &it : a1) cin>>it ; 
	for(auto &it : a2) cin>>it ; 
	
	merge(a1 , a2);
	
	debug(a1 , a2);
	
	
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
