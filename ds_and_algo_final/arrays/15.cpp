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

// This is our method in which we use floyd cycle to determine the entry of the cycle , first we have to understand that 
// if there is only one number which gets repeated the if we create a function as a[a[i]] then we will form a loop and the starting point
// of the loop is our repeating number . Go through the diagram of the cycle and equation for a better understanding . 


//Conditions : The only condition here is that only one number is being dublicated , and the array size is n+1 , and the numbers in the array ranges from 0-n . 

void solve()
{
	int n; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	int tortoise = a[0] , hare = a[0] ; 
	
	//finding the intersection point of the two runners . 
	
	while(tortoise!=hare){
		
		tortoise = a[tortoise] ;
		hare = a[a[hare]] ; 
		
	}
	
	// find the entrance of the cycle . 
	
	tortoise = a[0] ; 
	
	while(tortoise!=hare){
		tortoise = a[tortoise] ; 
		hare = a[hare] ; 
	}
	
	debug(hare);
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
