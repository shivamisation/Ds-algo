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
const int MAX = 30 ; 

struct key{
	
	int freq ;
	char ch ; 
	
	bool operator<(const key &k) const
	{
		return freq < k.freq ; 
	}
};

void solve()
{
	string s; cin>>s ; 
	
	int n = s.length();
	
	int cnt[MAX] = {0} ;
	
	for(int i=0 ; i<n ; i++){
		cnt[s[i] - 'a']++ ; 
	}
	
	priority_queue< key > pq ; 
	
	for(char c = 'a' ; c<= 'z' ; c++){
		if(cnt[c-'a']) pq.push(key{cnt[c-'a'] , c});
	}
	
	string str = "" ; 
	
	key prev {-1 , '#'} ; 
	
	
	
	while(!pq.empty()){
		
		key k = pq.top();
		pq.pop();
		str+= k.ch ; 
		
		
		if(prev.freq > 0) pq.push(prev);
		
		(k.freq)-- ; 
		prev = k ; 
	}
	
	if(n!= (int)str.length()) cout<<"Invalid" ; 
	
	else cout<<str ; 
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
