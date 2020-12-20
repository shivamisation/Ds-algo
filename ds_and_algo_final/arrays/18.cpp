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

//1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
//2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
//……….a) Traverse from right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
//……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
//……….c) After swapping, sort the string after the position of character found in step a. After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

//Optimizations in step b) and c)
//a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
//c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.
bool nxtpermute(string &s){
	
	int len=s.length();
	int i=len-2 ; 
	while(i>=0 && s[i]>=s[i+1]) i--; 

	//debug(i , s[i]);
	
	if(i<0) return false ; 
	
	else{
		int hi=len-1 , lo = i+1 , ind = -1 ; 
		
		while(lo<=hi){
			int mid = (hi+lo)/2 ; 
			if(s[mid]<=s[i]) hi = mid-1 ; 
			else {
				lo=mid+1 ; 
			    ind = mid ; 
			}
		}
		
		//debug(ind , s[ind] , i , s[i]);
		
		swap(s[i] , s[ind]);
		
	//	debug(s);
		
		sort(s.begin() + i+1, s.end());
		
		//debug(s);
		cout<<s ; 
		
		return true ; 
	}
}


void solve()
{
	string s; cin>>s ; 
	int cnt = 1 ; 
	
while(nxtpermute(s)==true){
	 cout<<endl ; 
	 cnt++ ; 
}

debug(cnt) ; 
	

	
	
	//cout<<s ; 
	
	
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
