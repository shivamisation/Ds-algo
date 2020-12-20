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


struct triplet
{
	int first , second , third ; 
};

void findsums(vector<int> a , vector<triplet> &ans , int sum){
	
	int l, r ,n = a.size();
	sort(a.begin() , a.end());
	for(int i=0 ; i<n-2 ; i++){
		l=i+1 , r = n-1 ; 
		
		while(l<r){
			if(a[i]+a[l]+a[r]==sum) {
				triplet temp ; 
				temp.first = a[i] ;
				temp.second = a[l] ;
				temp.third = a[r] ; 
				ans.push_back(temp);
				debug(i , l ,r);
				debug(a[i] , a[l] , a[r] , i , l , r); 
				break; 
				
			}
			
			if(a[i]+a[l]+a[r]<sum) l++ ;
			else r-- ; 
		}
	}
}

// Time complexity is O(n2) . We are using the two pointer approach ; 


void solve()
{
	int n , sum; cin>>n>>sum ; 
	
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 

	vector<triplet> ans ; 
	
	findsums(a , ans , sum);
	
	if(ans.empty()) cout<<0 ; 
	
	for(auto it : ans){
		cout<<it.first<<" "<<it.second<<" "<<it.third ; 
		nl ; 
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
