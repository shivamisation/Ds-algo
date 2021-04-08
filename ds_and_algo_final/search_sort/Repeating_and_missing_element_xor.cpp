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

// the nums in the array are between 1 to n 

void solve()
{
	// suppose x is the repeating element and y is the missing element ...
	// then we if we xor all elemtnts of the array and then xor all of them with
	// 1 to n , then we will be left with x (xor) y , now this number will have 
	// some set bits which will have some set bits of x and other of y ...it wont contain
	// any common set bits because we must have already cancelled it out , so we will 
	// separate the last bit of the xor , we could have chosen any one but its okay 
	// then we will get all the numbers which have the same bits set in the array , then we 
	// repeat this with the 1 to n and then will kinda get our answer .....
	
	
	int n ; cin>>n ;
	int x=0 , y=0 ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	int xor1 = 0 ; 
	
	for(int i=0 ; i<n ; i++){
		xor1 = xor1^a[i] ; 
	}
	
	for(int i=1 ; i<=n ; i++) xor1 = xor1^i ; 
	
	int set_bit_num = xor1 & ~(xor1 - 1) ; // rightmost set bit of the number 
	
	for(int i=0 ; i<n ; i++){
		if(a[i] & set_bit_num) {
			x = x^a[i] ; 
		}
		else {
			y = y^a[i] ;
		}
	}
	
	for(int i=1 ; i<=n ; i++){
		
		if(i & set_bit_num) x = x^i ; 
		else y = y^i ; 
	}
	
	// Checking which one is the repating element 
	int flag = 0 ; 
	
	for(auto it : a ){
		if(it==x) flag=1 ; 	
	}
	
	if(flag) {
		cout<<"The repeating element is "<<x<<" and the missing element is "<<y<<endl ; 
	}
	else {
		cout<<"The repeating element is "<<y<<" and the missing element is "<<x<<endl ; 
	}
	
	
	debug(x , y);
	
	
	
	
	
	
	
	
	
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
