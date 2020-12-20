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

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution
 * Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
 * Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
 * Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
 *
 * Time complexity is O(log(min(x,y))
 * Space complexity is O(1)
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation/4
 */


double findmed(vector<int> a, vector<int> b){
	if(a.size()>b.size()) return findmed(b,a);
	
	int x = a.size() , y = b.size();
	
	int lo = 0, hi = x ; 
	
	while(lo<=hi){
		int part_x = (lo+hi)/2 ;
		int part_y = (x+y+1)/2 - part_x ; 
		
		int mx_left_x = (part_x ==0)?zer:a[part_x-1] ; 
		int mn_right_x = (part_x==x)?inf:a[part_x] ; 
		
		
		int mx_left_y = (part_y ==0)?zer:b[part_y-1] ; 
		int mn_right_y = (part_y==y)?inf:b[part_y] ; 
		
		
		if(mx_left_x <= mn_right_y && mx_left_y<=mn_right_x){
			
			debug(part_x , part_y , x , y );
			
			if((x+y)%2==0) {
				return (double)(max(mx_left_x, mx_left_y) + min(mn_right_x , mn_right_y))/2 ; 
			}
			
			else {
				return (double)max(mx_left_x , mx_left_y);
			}
		}
		
		else if(mx_left_x > mn_right_y) hi = part_x -1 ; 
		else lo = part_x + 1 ; 
		
	}
	
	return -1 ; 
}


void solve()
{
	
	int n,m ; cin>>n>>m ; 
	
	vector<int> a(n) , b(m);
	for(auto &it : a) cin>>it ; 
	for(auto &it : b) cin>>it ; 
	
	debug(findmed(a, b)) ; 
	
	
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
