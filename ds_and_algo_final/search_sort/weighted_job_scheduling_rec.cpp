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
const int MAX = 1000 ; 
int dp[MAX] ; 
void speed() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

struct job {
	int start , finish , profit ; 
};

bool myfunction(job s1 , job s2){
	return s1.finish < s2.finish ; 
}

int search(vector<job> a , int ind){
	
	int ans = inf ; 
	
	int lo = 0 , hi = ind-1 ; 
	
	while(lo <= hi){
		
		int mid = (hi+lo)/2 ; 
		if(a[mid].finish <= a[ind].start){
			ans = min(ans , mid);
			lo = mid+1 ;
		}
		else hi = mid-1 ; 
	}
	
	if(ans == inf) return -1 ; 
	else return ans ; 
}

int profit(vector<job>a , int ind){
	
	if(ind ==0) return a[0].profit ; 
	
	if(dp[ind]!=-1) return dp[ind] ; 
	
	// we include the current job , and then we find the best suitable job which 
	// just occured before us , using binary search 
	
	int include = a[ind].profit ; 
	int best_before = search(a , ind);
	
	if(best_before!=-1) include+= dp[best_before]!=-1 ? dp[best_before] : profit(a , best_before);
	
	// we dont include the current job and see the result 
	
   int exclude =  dp[ind-1]!=-1 ? dp[ind-1] : profit(a , ind-1);
   
   return dp[ind] =  max(include  , exclude);
}

void solve()
{
	
	memset(dp , -1 , sizeof dp);
	vector<job> a = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
	//int n = a.size();
	
	cout<<profit(a , a.size()-1);
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
