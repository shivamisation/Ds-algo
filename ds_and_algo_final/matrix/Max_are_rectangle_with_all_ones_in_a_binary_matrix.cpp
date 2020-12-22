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

int hist(vector<int> a)
{
	int n = a.size();
	
	stack<int> s ; 
	
	int mx_area= 0 ; 
	int tp ;
	int area_with_top ; 
	
	
	int i = 0 ; 
	
	while(i<n){
		if(s.empty() or (a[s.top()] <= a[i])) s.push(i++);
		
		else {
			tp = s.top();
			s.pop();
			
			area_with_top = a[tp] * (s.empty()? i : i-1 - s.top()) ; 
			
			mx_area = max(mx_area , area_with_top);
		}
	}
	
	while(!s.empty()){
		tp = s.top();
		s.pop();
		area_with_top = a[tp] * (s.empty()? i : (i-1-s.top())) ; 
		mx_area = max(mx_area , area_with_top);
		
	}
	
	return mx_area ; 
}

void solve()
{
	int m , n ; cin>>n>>m ; 
	int ans = -inf ; 
	
	vector<vector<int>> a(n , vector<int>(m));
	
	for(auto &it : a){
		for(auto &its : it) cin>>its ; 
	}
	
	
	for(int r = 1 ; r<n ; r++){
		for(int c = 0 ; c<m ; c++){
			if(a[r][c]){
				a[r][c]+=a[r-1][c] ; 
			}
		}
		
		ans = max(ans , hist(a[r]));
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
