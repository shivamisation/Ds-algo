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

int findit(vector<pair<int,int>> merged , int k )
{
	int n = merged.size();
	
	for(int i=0 ; i<n ; i++){
		
		if(k<= abs(merged[i].second - merged[i].first + 1)){
			return merged[i].first + k-1 ;
		}
		k = k-abs(merged[i].second - merged[i].first + 1);
	}
	
	debug(k);
	
	if(k) return -1 ; 
}

void solve()
{
	
	int n ; cin>>n ; 
	vector<pair<int,int>> a(n);
	
	for(auto &it : a){
		int x , y;
		cin>>x>>y ; 
		it = {x ,y} ;
	}
	
	sort(a.begin() , a.end());
	
	vector<pair<int,int>> merged ; 
	merged.push_back(a[0]);
	
	for(int i=1 ; i<n ; i++){
		
		pair<int,int> prev = merged.back();
		pair<int,int> curr = a[i] ;
		
		// something like 1-3 and 2-4 so it becomes 1-4 
		if(curr.first >= prev.first and curr.first <= prev.second and curr.second > prev.second){
			merged.back().second = curr.second;
		}
		
		else if(curr.first > prev.second){
			//something like this 1-3 and 6 -10
			merged.push_back(curr);
		}	
	}
	
	debug(merged);
	
	n = merged.size();
	
	int q ; cin>>q ; 
	while(q--){
		int k ; cin>> k ; 
		cout<<findit(merged , k)<<"\n"	 ;
	}
	
	
	
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
