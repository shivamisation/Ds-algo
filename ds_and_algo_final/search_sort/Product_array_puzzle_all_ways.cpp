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

//Given an array arr[] of n integers, construct a Product Array prod[] (of same size) 
//such that prod[i] is equal to the product of all the elements of arr[] except arr[i].
 //Solve it without division operator in O(n) time.

void solve()
{
	int n; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	
	vector<int> prefix(n) , suffix(n) , prod(n);
	
	prefix[0] = 1 , suffix[n-1] = 1 ; 
	
	for(int i=1 ; i<n ; i++){
		prefix[i] = prefix[i-1]*a[i-1] ; 
	}
	
	for(int i=n-2 ; i>=0 ; i--){
		suffix[i] = suffix[i+1]*a[i+1] ; 
	}
	
	for(int i=0 ; i<n ; i++){
		prod[i] = suffix[i]*prefix[i] ; 
	}
	
	// instead of making the pref and the suff array , we could make just one array 
	// and then we would make a temp array and iterate over the array once in the forward 
	// direction creating the pref , using temp , and then in the reverse direction 
	// making the suffix array and also multiplying them ...
	
	

    //for (i = 0; i < n; i++) { 
        //prod[i] = temp; 
        //temp *= arr[i]; 
    //} 
  

    //temp = 1; 

    //for (i = n - 1; i >= 0; i--) { 
        //prod[i] *= temp; 
        //temp *= arr[i]; 
    //} 
	
	debug(prod , prefix , suffix);
	
}


// For constant space implementation 


//long double sum = 0; 
//#define EPS 1e-9 

    //for (int i = 0; i < n; i++) 
        //sum += (long double)log10(a[i]); 
        
         //for (int i = 0; i < n; i++) 
        //cout << (int)(EPS + pow((long double)10.00, 
                                //sum - log10(a[i]))) 
             //<< " "; 
             
             
             
             
 // another way for O(1)
 
   // total product of the array elements 
    //int prod = 1; 
    //for (int i = 0; i < n; i++) 
        //prod *= arr[i]; 
  
    // we know x/y mathematically is same 
     //as x*(y to power -1) 
    //for (int i = 0; i < n; i++) { 
        //cout << (

int main()
{
	speed(); 
    int T = 1;
    //cin >> T;
    while (T--){
    solve();
}
}
