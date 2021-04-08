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

  //so there are some plenty of ways to find the union and intersection of two arrays 
  //-> Brute force , initialise an empty answer array , then for every element in the 
	 //first array see , if that is present in the other one or not, if not then push that 
	 //element into the answer array , but first you have to copy the first array to the ans
	 
	 //for intersection , for every element in the first array see if it is already present
	 //in the second one , if it is , then push it to the answer 
	 
  
  
  //-> Sorting ------
  //sort both the arrays and then search the union and intersection in o(n+m) time
  
  
  //->Sorting and binary searching is one way, you can sort the smaller array and then 
    //search every element of the larger array in the smaller one . 
    
    
  //->Hashing=------------
   //use a set to find the union , copy every element of the first array in the set , then 
   //iterate over the other one and if the element is present in the set then print it ...for intersection


void solve()
{
	int n , m ; cin>>n>>m ; 
	vector<int> a(n) , b(m);
	
	for(auto &it : a) cin>>it ; 
	for(auto &it : b) cin>>it ; 
	
	int i=0 , j=0 ; 
	
	while(i<n && j<m){
		if(a[i]<b[j]) i++ ; 
		else if(b[j]<a[i]) j++ ; 
		
		else {
			cout<<a[i]<<" " ; 
			i++ , j++ ; 
		}
		
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
