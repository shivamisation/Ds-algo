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

vector<int> merge_it(vector<vector<int>> mat)
{
	vector<int> output ; 
	
	priority_queue<pair<int,pair<int,int>>> pq ; 
	
	for(int i=0 ; i<(int)mat.size() ; i++) pq.push({mat[i][0] , {i,0}});
	
	while(!pq.empty()){
		pair<int,pair<int,int>> curr = pq.top();
		pq.pop();
		
		int i = curr.second.first ; 
		int j = curr.second.second ; 
		
		output.push_back(curr.first);
		
		if(j+1 < (int)mat[i].size()) pq.push({mat[i][j+1] , {i , j+1}});
	}
	
	return output ; 
	
}

void solve()
{
	
	vector<vector<int>> mat ; 
	
	mat =  {{2, 6, 12, 34},
            {1, 9, 20, 1000},
            {23, 34, 90, 2000}};
            
    
   debug(merge_it(mat)) ;
	
	
	
	
	

	
	
	
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
