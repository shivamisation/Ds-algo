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
int x[] = {-1 , -1 , -1 , 0 , 0 ,1 , 1 , 1} ;
int y[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};
const int R = 3 , C = 14 ; 

 char grid[R][C] = { "GEEKSFORGEEKS", 
                        "GEEKSQUIZGEEK", 
                        "IDEQAPRACTICE" }; 
                        

bool pat_search(int row , int col , string word){
	
	if(grid[row][col] != word[0]) return false ; 
	
	int len = word.length();
	int ind ;
	
	for(int dir = 0 ; dir<8 ; dir++){
		
		int rd = row + x[dir] , cd = col + y[dir] ; 
	
		for( ind=1 ; ind<len ; ind++){
			
			if(rd >= R || rd<0 || cd>=C || cd<0) break ; 
			
			if(grid[rd][cd]!=word[ind]) break ; 
			
			rd+= x[dir] , cd+=y[dir] ; 
			
		}
		
		if(ind == len) return true ; 
	}
	
	return false ; 
}
                        

void search(string word){
	
	for(int row = 0 ; row<R ; row++){
		for(int col = 0 ; col<C ; col++){
			if(pat_search(row , col , word)){
				cout<<"pat found at "<<row<<" , "<<col<<endl; 
			}
		}
	}
}



void solve()
{
	search("GEEKS");
	
	
	
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
