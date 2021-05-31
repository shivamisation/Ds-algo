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

vector<int> lps_gen(string pat){
	int n = pat.length();
	vector<int> lps(n);
	
	int len =0 , i = 1 ;
	
	while(i<n){
		if(pat[i]==pat[len]){
			len++ ;
			lps[i]=len ;
			i++;
		}
		else{
			if(len) len = lps[len-1] ;
			else {
				lps[i]=0 ;
				i++ ;
			}
		}
	}
	
	return lps ;
}

void KMP_search(string pat, string text){
	
	int m = pat.length();
	int n = text.length();
	
	vector<int> lps = lps_gen(pat);
	
	int i=0 , j=0 ; 
	
	while(i<n){
		if(pat[j]==text[i]){
			j++ ;
			i++ ;
		}
		
		if(j==m){
			cout<<"Index found at index id "<<i-j<<"\n" ; 
			j=lps[j-1] ; 
		}
		
		else if(i<n and pat[j]!=text[i]){
			
			if(j) j = lps[j-1] ;
			else i++ ; 
			
		}
	}
}


void solve()
{
	
	string text = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	
	vector<int> lps = lps_gen(pat);
	debug(lps);
	
	KMP_search(pat , text);
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
