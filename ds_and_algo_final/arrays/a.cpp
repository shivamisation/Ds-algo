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
vector<int> a ;

int partition(int low , int high){

	int i = low - 1 ; 
	int pivot = a[high] ;
	// we cant do this because our implementation of partition is bases on the presense 
	// of the pivot on the last index .....
	
	for(int j=low ; j<=high-1 ; j++){
		if(a[j]<pivot){
			i++ ;
			swap(a[i] , a[j]);
		}
	}
	swap(a[i+1] ,a[high]);
	return i+1 ;
}

void quick_sort(int low , int high){
	if(low<high){
		// to implement randomized quick sort 
		int random = low + rand()%(high-low);
		swap(a[random] ,a[high]);
		int pi = partition(low , high);
		quick_sort(low , pi-1);
		quick_sort(pi+1 , high);
	}
}

void solve()
{
	srand(time(0)) ;
 
	a = {9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1} ;
	
	quick_sort(0 ,a.size()-1);
	
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
