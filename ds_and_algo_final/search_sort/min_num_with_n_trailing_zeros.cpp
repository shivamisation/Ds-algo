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
	// just notice that we the upper bound will be 5*n , if we want n trailing zeros 
	// then the largest numberr which has that many zeros will be less than 5*n 
	// just do binary search 
	
	bool check(int p, int n) 
{ 
    int temp = p, count = 0, f = 5; 
    while (f <= temp) 
    { 
        count += temp/f; 
        f = f*5; 
    } 
    return (count >= n); 
} 


int findNum(int n) 
{ 
    // If n equal to 1, return 5. 
    // since 5! = 120. 
    if (n==1) 
        return 5; 
  
    // Initalising low and high for binary 
    // search. 
    int low = 0; 
    int high = 5*n; 
  
    // Binary Search. 
    while (low <high) 
    { 
        int mid = (low + high) >> 1; 
  
        // Checking if mid's factorial contains 
        // n trailing zeroes. 
        if (check(mid, n)) 
            high = mid; 
        else
            low = mid+1; 
    } 
  
    return low; 
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
