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

// dont check geek for geeks , its bad ...

// geeks for geeks will confuse you dont check please ....

int check_in_dict(string s){
	vector<string> dict =  {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream"}; 

	for(int i=0 ; i<(int)dict.size() ; i++){
		if(s.compare(dict[i])==0) return 1; 
	}
	
	return 0 ;                      
                
}

map<string , int> dp ; // or you might use unordered_map

int word_Break(string s){
	
	int size = s.length();
	
	if(size==0) return 1 ; 
	
	if(dp[s]!=0) return dp[s] ;
	
	for(int i=1 ; i<=size ; i++){
		int flag = 0 ; 
		
		string sb = s.substr(0,i);
		
		flag = check_in_dict(sb);
		
		if(flag==1 and word_Break(s.substr(i , size-i))==1) return dp[s] = 1 ; 
	}
	
	return dp[s] = -1 ; 
}


void solve()
{
	string s ; cin>>s ; 
	
	debug(word_Break(s));
	
	
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
