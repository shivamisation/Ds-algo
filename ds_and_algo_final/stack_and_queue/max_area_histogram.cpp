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

void solve()
{
	vector<int> hist = {6, 2, 5, 4, 5, 1, 6} ;
	int n = hist.size();
	
	vector<int> right(n);
	
	stack<int> s ; 
	
	for(int i=0 ; i<(int)hist.size() ; i++){
		
		while(!s.empty() and hist[s.top()]>hist[i]){
			right[s.top()] = i ; 
			s.pop();
		}
		
		s.push(i);
	}
	
	while(!s.empty()){
		right[s.top()] = -1 ; 
		s.pop();
	}
	
	
	vector<int> left(n);
	
	for(int i=n-1 ; i>=0 ; i--){
		
		while(!s.empty() and hist[s.top()]>hist[i]){
			left[s.top()] = i ; 
			s.pop();
		}
			s.push(i);
	}
	
	while(!s.empty()){
		left[s.top()] = -1 ; 
		s.pop();
	}
	
	int max_area = zer , area = 0 ;
	
	for(int i = 0 ; i<n ; i++){
		int len ;
		
		if(right[i]==-1 and left[i]!=-1) len = n-1 - left[i] ; 
		else if(right[i]!=-1 and left[i]==-1) len = right[i]; 
		else if (right[i]==-1 and left[i]==-1) len = n ; 
		else {
			len = right[i] - left[i] - 1 ;
		}
		
		area = hist[i]*(len) ;
		max_area = max(max_area , area);
		debug(area);
	}
	
	debug(max_area);
	
	
	
	
	
	debug(right);
	debug(left);
		
	
	
	
	
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
