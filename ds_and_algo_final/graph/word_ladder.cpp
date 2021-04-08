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

int bfs(string start , string target , set<string>& D){
	
	if(D.find(target)==D.end()) return 0 ; 
	
	int level = 0 , wordlength = start.size();
	
	queue<string> q ;
	q.push(start);
	
	while(!q.empty()){
		++level ;
		int qsize= q.size();
		
		for(int i=0 ; i<qsize ; i++){
			string word = q.front();
			q.pop();
			
			for(int pos = 0 ; pos<wordlength;++pos){
				char oc = word[pos] ;
				for(char c = 'a' ; c<='z' ; c++){
					word[pos] = c ;
					
					if(word==target) return level+1 ;
					if(D.find(word)==D.end()) continue ; 
					D.erase(word);
					q.push(word);
				}
				word[pos] = oc ; // resotre word 
			}
		}
	}
	
	return 0 ; 
	
}



void solve()
{
	set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    
    debug(bfs(start , target , D));
	
	
	
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
