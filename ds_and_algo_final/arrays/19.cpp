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

int merge(vector<int> &a , vector<int> &temp , int left , int mid , int right){
	
	int i , j , k , inv = 0 ; 
	
	i = left , j = mid+1 , k = left ; 
	
	while((i<=mid) && (j<=right)){
		if(a[i]<=a[j]){
			temp[k++]=a[i++] ; 
		}
		else {
			temp[k++] = a[j++] ; 
			
			inv+=mid-i+1 ; 
		}
	}
	
	while(i<=mid){
		temp[k++] = a[i++] ; 
	}
	
	while(j<=right){
		temp[k++] = a[j++] ; 
	}
	
	for(i = left ; i<=right ; i++){
		a[i] = temp[i] ; 
	}
	
	return inv ; 
}

int mergesort(vector<int> &a , vector<int> &temp , int left , int right){
	
	int inv = 0 , mid; 
	
	if(right>left){
		
		mid = (left+right)/2 ; 
		
		inv+= mergesort(a , temp , left , mid);
		inv+= mergesort(a , temp , mid+1 , right);
		
		inv+= merge(a , temp , left , mid , right);	
	}
	
	return inv ; 
}

void solve()
{
	int n ; cin>>n ; 
	vector<int> a(n);
	for(auto &it : a) cin>>it ; 
	vector<int> temp(n);
	
	cout<<mergesort(a , temp , 0 , a.size()-1 );
	debug(a);
	debug(temp);
	
	
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
