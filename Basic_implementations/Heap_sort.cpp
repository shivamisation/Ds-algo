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

void heapify(vector<int> &a , int i , int n){
	
	int left = 2*i , right = 2*i+1 , largest = -1 ; 
	
	if(left <= n and a[left] > a[i] ) largest = left ; 
	else largest = i ; 
	
	if(right <= n and a[right] > a[largest]) largest = right ; 
	
	if(largest != i){
		swap(a[largest] , a[i]);
		heapify(a , largest , n);
	}
}

void build_heap(vector<int> &a){
	int n = a.size()-1;
	
	for(int i=n/2 ; i>=1 ; i--){
		heapify(a , i , n);
	}
}

void heap_sort(vector<int> &a){
	
	int length = a.size()-1;
	
	for(int i=length ; i>=2 ; i--){
		swap(a[i] , a[1]);
		debug(a);
		heapify(a , 1 , i-1);
	}
}

void solve()
{
	int n; cin>>n ; 
	vector<int> a(n+1);
	for(int i=1 ; i<=n ; i++) cin>>a[i] ; 
	
	build_heap(a);
	
	debug(a);
	
	heap_sort(a);
	
	puts("after heap sort");
	
	debug(a);
	
	
	
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
