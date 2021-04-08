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

int solve1(string s){
	stack<int> st ; 
	
	for(auto it : s){
		if(isdigit(it)) st.push(it-'0');
		
		else {
			int val1 = st.top() ; st.pop();
			int val2 = st.top() ; st.pop();
			
			switch(it){
				case '+': st.push(val1+val2);break;
				case '-': st.push(val2-val1);break;
				case '*': st.push(val2*val1);break;
				case '/': st.push(val2/val1);break;
			}
		}
	}
	
	return st.top();
}

int solve2(string s){
	
	stack<int> st ; 
	
	for(int i=0 ; i<(int)s.length() ; i++){
		
		if(s[i] == ' ') continue; 
		
		else if(isdigit(s[i])){
			int num = 0 ;
			
			while(isdigit(s[i])){
				num = num*10 + (int)(s[i] - '0') ;
				i++ ;
			}
			i-- ; 
			
			st.push(num);
		}
		
		else {
			int val1 = st.top() ; st.pop();
			int val2 = st.top() ; st.pop();
			
			switch(s[i]){
				case '+' : st.push(val2+val1); break ;
				case '-' : st.push(val2 - val1); break;
				case '*' : st.push(val2*val1); break;
				case '/' : st.push(val2/val1); break; 
			}
		}
	}
	
	return st.top();
	

}

void solve()
{
	string str2 =  "100 200 + 2 / 5 * 7 +";
	string str1 = "231*+9-";  
	
	cout<<solve1(str1);
	nl ;
	cout<<solve2(str2);
	

	
	
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
