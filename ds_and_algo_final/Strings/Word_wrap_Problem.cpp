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


int print_path(vector<int> path , int n){
	
	int line_number ; 
	
	if(path[n]==1) line_number = 1 ; 
	
	else line_number = print_path(path , path[n] - 1) + 1;
	
	cout<<"Line"<<line_number<<" from word "<<path[n]<<" to "<<n<<"\n" ; 
	
	return line_number ; 
}

void solve()
{
	int n,m ; cin>>n>>m; 
	vector<int> words(n+1);
	
	for(int i=1 ; i<=n ; i++) cin>>words[i] ; 
	
	
	vector<vector<int>> space(n+1 , vector<int>(n+1));
	vector<vector<int>> line_cost(n+1 , vector<int>(n+1));
	vector<int> cost(n+1);
	vector<int> path(n+1);  
	
	for(int i=1 ; i<=n ; i++){
		
		space[i][i] = m - words[i] ; 
		for(int j = i+1 ; j<=n ; j++){
			space[i][j] = space[i][j-1] - words[j] - 1 ; 
		}
	}
	
	
	for(int i=1 ; i<=n ; i++){
		for(int j=i ; j<=n ; j++){
			if(space[i][j] < 0) line_cost[i][j]= inf ; 
			
			else if (j==n && space[i][j] >=0 ) line_cost[i][j]=0 ; 
			
			else line_cost[i][j] = space[i][j]*space[i][j] ; 
		}
	}
	
	
	// real dp starts here . ...
	
	cost[0] = 0 ; 
	
	for(int i=1 ; i<=n ; i++){
		cost[i] = inf ; 
		
		for(int j=1 ; j<=i ; j++){
			if(cost[j-1] != inf and line_cost[j][i]!=inf and (cost[j-1] + line_cost[j][i] < cost[i])){
				
				cost[i] = cost[j-1] + line_cost[j][i] ; 
				path[i]=j ; 
			}
		}
	}
	
	print_path(path , n);
	
	//TEST INPUT : 4 6    3 2 2 5 


	
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
