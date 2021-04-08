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

// we use backtracking here 


bool verify(string &s , int i , int j){
	
	if(j-i > 3) return false ; 
	
	
	if(j-i >1 and s[i] == '0') return false ; 
	
	
	if(j-i ==3 and s.substr(i , j-i) > "255") return false ; 
	
	return true; 
}



void ip(string &s , int i , int cntDot , vector<string> &ans){
	
	if(cntDot==3){
		
		//debug(s);
		if(!verify(s , i , s.size())) return ; 
		
		
		
		ans.push_back(s);
		return ; 
	}
	
	string t ; 
	
	for(int j=i+1 ; j<=i+3 ; j++){
		
		t=s ; 
		
		//verify if s[i...j] is valid 
		
		if(!verify(s,i,j)) return ; 
		
		//put dot at j 
		
		t.insert(t.begin()+j , 1 , '.');
		
		// if dot at end ---reject 
		
		if(t[t.size() -1] == '.') return ; 
		
		ip(t, j+1 , cntDot+1 , ans);	
	}
}

void solve()
{
	string s = "25525511135" ; 
	
	vector<string> ans ; 
	
	 ip(s, 0 , 0 , ans);
	 
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
