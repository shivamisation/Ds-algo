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

//Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array.
struct Heapnode{
	int val ;
	int r ;
	int c ; 
};

bool operator>( const Heapnode& a ,const Heapnode &b){
	return a.val>b.val ; 
}

void solve()
{
	
	int k ; cin>>k ; 
	vector<vector<int>> a = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                }; 
    int n = a.size();
    int m = a[0].size();
	
	priority_queue<Heapnode , vector<Heapnode> , greater<Heapnode>> q ; 
	
	for(int c = 0 ; c<m ; c++){
		Heapnode temp ; 
		temp.val = a[0][c] ;
		temp.r = 0; 
		temp.c = c ; 
		q.push(temp);
	}
	
	for(int i=0 ; i<k-1 ; i++){
		Heapnode temp= q.top(), another ; 
		q.pop();
		int next_val = (temp.r<(n-1)?a[temp.r+1][temp.c]:inf) ;
		another.val = next_val ;
		another.r =temp.r+1 ;
		another.c = temp.c;
		q.push(another);
	}
	
	Heapnode temp = q.top();
	cout<<temp.val; 
	
	
	
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
