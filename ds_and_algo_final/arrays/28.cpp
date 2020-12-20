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

int mul(int x , int sz , vector<int> &ans){
	
	int carry=0 ; 
	
	for(int i=0 ; i<sz ; i++){
		int prod = ans[i]*x + carry ; 
		ans[i]=prod%10 ;
		carry=prod/10 ; 
	}
	
	while(carry){
		ans[sz]=carry%10 ; 
		carry/=10 ; 
		sz++ ; 
	}
	
	return sz ; 
}

void fact(int num){
	vector<int> ans(10000);
	
	ans[0]=1 ; 
	int sz = 1 ; 
	
	for(int x =2 ; x<=num ; x++){
		sz = mul(x , sz , ans);
	}
	
	cout<<"The factorial is "; 
	
	for(int i=sz-1 ; i>=0 ; i--){
		cout<<ans[i] ; 
	}
	nl ; 
}

void solve()
{
	int num ; 
	cin>>num ; 
	fact(num);
	
	
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
