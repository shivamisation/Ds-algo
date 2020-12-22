 
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
vector<int> ans ; 
int n , m ; 

//Time complexity O(N2logn) 

struct MinHeapNode
{
	int element ; // The element to be sorted 
	int i ; // index of the row from which the element is taken 
	int j ; //index of the next element to be picked from row 
};

bool operator>(const MinHeapNode& lhs , const MinHeapNode& rhs )
{
	return lhs.element > rhs.element ; 
}

void printsorted(vector<vector<int>> a){
	
	priority_queue<MinHeapNode , vector<MinHeapNode> , greater<MinHeapNode>> q ;
	
	for(int r = 0 ; r<n ; r++){
		MinHeapNode mh;
		mh.element=a[r][0] ; 
		mh.i = r ; 
		mh.j = 1 ; 
		q.push(mh);
	}
	
	for(int count = 0 ; count<n*m ; count++)
	{
		MinHeapNode mh = q.top();
		q.pop();
		ans.push_back(mh.element);
		
		if(mh.j < n)
		{
			mh.element = a[mh.i][mh.j] ; 
			mh.j+=1 ; 
		}
		
		else mh.element=inf ; 
		
		q.push(mh);
	}
}



void solve()
{
	cin>>n>>m ;
	
	vector<vector<int>> a(n , vector<int>(m));
	
	for(auto &it : a){
		for(auto &its : it) cin>>its ; 
	}
	
	printsorted(a);
	
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
