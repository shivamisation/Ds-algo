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


// Just dont use any extra space was the constraint and the rest was too easy !

//never do this ---> (a.low = temp.second = a.high) , triple brackets dont work just know that they dont work ! , using basic divide and conquer , and some easy 

// this used the divide and conquer approach , by the way the easy apprach everybody knows so there was no fun in it , so divide and conquer approach also teaches you a little bit of recursion so it would be better for everybody !!

// the easy method uses a simple linear search and thats it !

// Time Complexity is O(n)
//Space Complexity is O(logn)

pair<int,int> get_ans(vector<int> a , int low , int high){
	pair<int,int> temp ; 
	
	//debug(low, high);
	if(low==high){
		temp.first = a[low] ;
		temp.second = a[low] ; 
		//return temp ; 
	}
	 else if(high == low+1){
		temp.first = max(a[low] , a[high]);
		temp.second = min(a[low] , a[high]);
		//return temp ; 
	}
	
	else{
		
		int mid = (high+low)/2 ; 
		
		pair<int,int> left = get_ans(a , low , mid);
		pair<int,int> right = get_ans(a , mid+1 , high);
		
		temp.first = max(left.first , right.first);
		temp.second = min(left.second , right.second);
	}
	
	//debug(temp);
	return temp ; 
}

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n); 
	for(auto &it : a) cin>>it ; 
	
	pair<int,int> ans = get_ans(a, 0 , a.size()-1);
	
	debug(ans);
	

	
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
