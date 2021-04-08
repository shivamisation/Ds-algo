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

int mx_prod(vector<int> &a){
	
	int mx = 1 ; 
	int mn = 1 ; 
	
	int n = a.size() , ans = 0 , flag = 0 ; 
	
	for(int i=0 ; i<n ; i++){
		if(a[i]>0){
			mx*=a[i] ; 
			
			mn = min(mn*a[i] , 1);
			flag=1 ; 
		}
		
		else if(a[i]==0){
			mx=1 , mn = 1 ; 
		}
		
		else{
			int temp = mx ; 
			mx = max(mn*a[i] , 1);
			mn = temp*a[i] ; 
		}
		
		ans = max(ans , mx);
	}
	
	if(flag==0 && ans==0) return 0 ; 
	else return ans ; 
}

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	cout<<mx_prod(a);
	
	
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
