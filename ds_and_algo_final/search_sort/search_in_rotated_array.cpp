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

// well this solution is quite complex , but you could also find the pivot using
// binary search and then decide where to find the number in the array , the left side or
// the right side ......

int s(vector<int> nums , int l , int h , int key){
	
	if(l > h) return -1 ; 
	
	int mid = l + (h-l)/2 ; 
	
	if(nums[mid] == key) return mid ; 
	
	
	if(nums[l] <= nums[mid]){ // if a[l ...mid] is sorted
		
		if(key >= nums[l] and key <= nums[mid]) return s(nums , l , mid-1 , key);
		// if key exists in this region then it must be here 
		
		//if not here then it must in the second half 
		return s(nums , mid+1 , h , key);
	}
	
	// if not sorted then the other one must be sorted 
	
	if(key >= nums[mid] and key <= nums[h]) return s(nums , mid+1 , h , key);
	
	return s(nums , l , mid-1 , key);
}

void solve()
{
	vector<int> nums = { 4, 5, 6, 7, 8, 9, 1, 2, 3 }; 
	int n = nums.size();
	int key = 6 ; 
	
	cout<<s(nums , 0 , n-1 , key);
	
	
	
	
	
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
