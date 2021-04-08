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
const int ROW = 3 , COL = 5 ; 

int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

char mat[ROW][COL]= { {'B', 'N', 'E', 'Y', 'S'}, 
                          {'H', 'E', 'D', 'E', 'S'}, 
                          {'S', 'G', 'N', 'D', 'E'} 
                        }; 
                        
                        
  
string word = "SGNDE" ; 

bool isValid(int row , int col , int prevRow , int prevCol){
	
	return ((row >=0) and (row<ROW) and (col>=0) and (col<COL) and !(row == prevRow and col==prevCol)) ;
}

void dfs(int row , int col , int prevRow , int prevCol , string path , int ind , int n){
	
	if(ind > n || mat[row][col] != word[ind]) return ;
	
	path += string(1 , word[ind]) + "(" + to_string(row) + "," + to_string(col) + ")";
	
	if(ind == n){
		cout<<path<<endl ; 
		return ; 
	}
	
	for(int k=0 ; k<8 ; k++){
		
		if (isValid(row + rowNum[k], col + colNum[k], prevRow, prevCol)) {
			
			dfs(row + rowNum[k] , col + colNum[k] , row , col , path , ind+1 , n);
		}  
	}
}



void findWords(int n){
	
	for(int i=0 ; i<ROW ; i++){
		for(int j=0 ; j<COL ; j++){
			
			if(mat[i][j] == word[0]) dfs(i , j , -1 , -1 , "" , 0 , n);
			
		}
	}
}

void solve()
{
	findWords(word.length() -1);
	
	
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
