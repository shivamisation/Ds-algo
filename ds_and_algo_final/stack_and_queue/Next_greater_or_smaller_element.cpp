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

void solve()
{
	vector<int> a = {4 , 8 , 5 , 2 , 25} ;
	int n = a.size();
	
	stack<int> s ; 
	
	// Next greater
	
	cout<<"\nFirst methond for NGE\n\n" ;
	
	for(int i=0 ; i<n ; i++){
		
		while(!s.empty() and s.top() < a[i] ){
			cout<<s.top()<<" --> "<<a[i]<<"\n" ; // you could use a map or something
												// similar  
			s.pop();
		}
		
		s.push(a[i]);
	}
	
	while(!s.empty()){
		cout<<s.top()<<" --> "<<"-1"<<"\n" ;
		s.pop();
	}
	
	//Next greater in another way .. iterating from back
	
	cout<<"\nBack Iteration method\n";
	
	for(int i=n-1 ; i>=0 ; i--){
		
		while(!s.empty() and s.top() < a[i]) s.pop();
		
		if(!s.empty()) cout<< a[i] <<" --> "<< s.top() <<"\n" ;
		else cout<<a[i]<<" --> "<<-1<<"\n" ;
		s.push(a[i]);	
		
	}
	
	
	
	

	
	cout<<"\n\nNow NSE\n\n" ;
	
	while(!s.empty()) s.pop();
	
	for(int i=0 ; i<n ; i++){
		
		while(!s.empty() and s.top() > a[i] ){
			cout<<s.top()<<" --> "<<a[i]<<"\n" ;
			s.pop();
		}
		
		s.push(a[i]);
	}
	
	while(!s.empty()){
		cout<<s.top()<<" --> "<<"-1"<<"\n" ;
		s.pop();
	}
	
	cout<<"\nBack Iteration method\n";
	
	
	for(int i=n-1 ; i>=0 ; i--){
		
		while(!s.empty() and s.top()>a[i]) s.pop();
		
		if(!s.empty()) cout<<a[i]<<" --> "<<s.top()<<"\n" ;
		else cout<<a[i]<<" --> "<<-1<<"\n" ;
		s.push(a[i]);	
		
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
