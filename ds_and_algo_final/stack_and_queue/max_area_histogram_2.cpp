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
	
	stack<int> s ;
	
	int max_area = zer , area = -1 ; 
	
	int i=0 ;
	while(i<n){
		
		if(s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
		
		else {
			int tp = s.top();
			s.pop();
			
			area = hist[tp]*(s.empty() ? i : i-s.top() - 1) ;
			max_area = max(area, max_area);
		}
	}
	
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		area = hist[tp]*(s.empty() ? i : i-s.top() - 1) ;
		area = max(max_area , area);
	}
	
	cout<< max_area; 
	

	
	
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
