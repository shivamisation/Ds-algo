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

vector<int> get_vec(vector<int> v , int l , int r){
	vector<int> temp ; 
	
	for(int i = l ; i<=r ; i++) temp.push_back(v[i]);
	
	return temp ; 
}

int median(vector<int> a , int n){
	
	if(n%2==0){
		return (a[n/2] + a[n/2 -1])/2 ; 
	}
	return a[n/2] ; 
}

int get_median(vector<int> a , vector<int> b , int n)
{
	debug(a , b , n);
	if(n==1) return(a[0] + b[0])/2 ; 
	if(n==2) {
		debug(max(a[0] , b[0]) + min(a[1] , b[1]));
		return (max(a[0] , b[0]) + min(a[1] , b[1]))/2 ; 
	} 
	
	int m1 = median(a , n);
	int m2 = median(b , n);
	
	if(m1==m2) return m1 ; 
	
	if(m1 < m2){
		if(n%2==0)
		{
			vector<int> f = get_vec(a , n/2-1 , n-1);
			vector<int> s = get_vec(b , 0 , n/2);
			
			return get_median(f , s , n/2 + 1);
	    }
		else 
		{
			vector<int> f = get_vec(a , n/2 , n-1);
			vector<int> s = get_vec(b , 0 , n/2);
			
			return get_median(f , s , n/2+1);
		}
	}
	
	else {
		
		if(n%2==0)
		{
			vector<int> f = get_vec(b , n/2-1 , n-1);
			vector<int> s = get_vec(a , 0 , n/2);
			
			return get_median(f , s , n/2 + 1);
	    }
		else 
		{
			vector<int> f = get_vec(b , n/2 , n-1);
			vector<int> s = get_vec(a , 0 , n/2);
			
			return get_median(f , s , n/2+1);
		}
		
	}
	
	
}

void solve()
{
	int n; cin>>n ; 
	vector<int> a(n) , b(n);
	for(auto &it : a) cin>>it ; 
	for(auto &it : b) cin>>it ; 
	
	cout<<get_median(a , b , n) ; 
	
	
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
