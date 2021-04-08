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
const int MAX = 256 ; 

void solve()
{
	string str = "this is a test string";
    string pat = "tist";
    
    int str_len = str.length();
    int pat_len = pat.length();
    
    if(str_len < pat_len) {
		puts("invalid");
		return ; 
	}
	
	int hash_str[MAX]={0} , hash_pat[MAX]={0} ;
	
	for(int i=0 ; i<pat_len ; i++) hash_pat[pat[i]]++ ; 
	
	int start = 0 , start_ind = -1 , min_len = inf ; 
	
	int cnt = 0 ;
	
	for(int j = 0 ; j<str_len ; j++){
		
		hash_str[str[j]]++ ; 
		
		if(hash_str[str[j]] <= hash_pat[str[j]]) cnt++ ; 
		
		if(cnt == pat_len){
			
			while(hash_str[str[start]] > hash_pat[str[start]]) {
				hash_str[str[start]] -- ; 
				start ++ ; 
			}
			
			int len_window = j - start + 1 ; 
			
			if(min_len > len_window){
				min_len = len_window ; 
				start_ind = start ; 
			}
			
			
		}
	}
	
	if(start_ind== -1){
				puts("invalid");
			}
			
	cout<<str.substr(start_ind , min_len);
	
	
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
