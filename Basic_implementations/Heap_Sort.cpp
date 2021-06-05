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
#define prec(n) fixed<<setprecision(n)

void speed() { ios_base::sync_with_stdio(false);cin.tie(NULL);}


void heapify(vector<int> &a , int ind , int n){
	int max_ind = ind ;
	int l = 2*ind + 1 ;
	int r = 2*ind + 2 ;
	
	if(l<n and a[l]>a[max_ind]) max_ind = l ;
	if(r<n and a[r]>a[max_ind]) max_ind = r ;
	
	if(max_ind!=ind){
		swap(a[ind] , a[max_ind]);
		heapify(a , max_ind , n);
	}
}

void heapsort(vector<int> &a){
	int n = a.size();
	for(int i=n/2 ; i>=0 ; i--){
		heapify(a , i , n);
	}
	
	for(int i=n-1 ; i>0 ; i--){
		swap(a[0] , a[i]);
		heapify(a , 0 , i);
	}
	
}

void solve()
{
	vector<int> a = {4, 5 , 8 , 9 , 3} ;
	heapsort(a);
	debug(a);
	

	
	
	
}

int main()
{
	speed(); 
    int T = 1;
    cin >> T;
    while (T--){
    solve();
}
}
