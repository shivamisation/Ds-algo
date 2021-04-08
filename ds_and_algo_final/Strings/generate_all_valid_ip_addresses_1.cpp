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

vector<string> ip(string s){
	
	vector<string> ret ; 
	string ans ; 
	
	for(int a=1 ; a<=3 ; a++){
		for(int b=1 ; b<=3 ; b++){
			for(int c=1 ; c<=3 ; c++){
				
				int d = s.size() -a -b -c; 
				
				if(d>=1 and d<=3){
					
					int A = stoi(s.substr(0,a));
					int B = stoi(s.substr(a,b));
					int C = stoi(s.substr(a+b , c));
					int D = stoi(s.substr(a+b+c , d));
					
					if(A<=255 and B<=255 and C<=255 and D<=255){
						if((ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D)).length() == s.length() + 3) 
						{
							ret.push_back(ans);
						}
					}
				}
			}
		}
	}
	
	return ret ; 
	
}

void solve()
{
	
	string s = "25525511135" ; 
	
	debug(ip(s));
	
	
	
	
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
