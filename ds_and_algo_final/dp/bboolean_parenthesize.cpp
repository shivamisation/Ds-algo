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
string s ;

int dp[1001][1001][2] ;

int parenthise(int i , int j , int isTrue){
	
	if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue] ;
	
	if(i>j) return false ;
	
	if(i==j){
		if(isTrue){
			return s[i] == 'T' ;
		}
		else return s[i] == 'F' ;
	}
	
	int ans = 0 ;
	
	for(int k = i+1 ; k<j ; k+=2){
		
		/*
		 * the following lines of codes can be optimised , by first cheking the dp table
		 * then calling them ... for leftT , rightT ... and so on , this would increase 
		 * the efficiency of the code . 
		 * 
		 * */
		
		int leftT = parenthise(i , k-1 , 1);
		int rightT = parenthise(k+1 , j , 1);
		int leftF = parenthise(i,k-1 , 0);
		int rightF = parenthise(k+1 , j , 0);
		
		
		if(s[k] == '&'){
			if(isTrue){
				ans += leftT*rightT ;
			}
			else ans+= leftT*rightF + leftF*rightT + leftF*rightF ;
		}
		
		else if(s[k] == '|'){
			if(isTrue){
				ans+= leftT*rightT + rightF*leftT + rightT*leftF ;
			}
			else ans+= leftF*rightF ;
		}
		
		else if(s[k]== '^'){
			if(isTrue){
				ans+= leftT*rightF + leftF*rightT ;
			}
			else ans+= leftT*rightT + leftF*rightF ;
		}
	}
	
	return dp[i][j][isTrue] = ans ; 
}


void solve()
{
	
	memset(dp , -1 , sizeof dp);
	
	s = "T|T&F^T" ;
	cout<<parenthise(0 , s.length()-1 , 1);
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
