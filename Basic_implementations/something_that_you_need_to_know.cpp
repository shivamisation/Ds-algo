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

void solve()
{
	
	//change the upperlowercase of strings 
	
	string name = "shiVam is mY NAME" ; 
	transform(name.begin() , name.end() , name.begin() , ::tolower);
	debug(name);
	
	//convert integers to string 
	
	int  num = 9890 ; 
	string temp = to_string(num);
	
	debug(temp);
	
	
	// change strings to numbers 
	
	string number = "9988098" ;
	string hex_num = "FFFFF" ;  
	
	int ans1 = stoi(number , nullptr , 10);
	long int ans2 = stol(number , nullptr , 10);
	ll ans3 = stoll(number , nullptr , 10);
	int int_hex_num = stoi(hex_num , nullptr , 16);
	
	debug(ans1, ans2 , ans3 , int_hex_num);
	
	
	// tokenise a string with spaces and other characters 
	
	string line = "My life has changed because ab mai hari ka hogya " ; 
	
	istringstream iss(line);
	string token ; 
	
	unordered_map<string,int> words;
	
	while(getline(iss , token , ' ')){
		words[token]++ ; 
	}
	
	
	debug(words);
	
	/// taking input of a line which has words 
	
	string str ; 
	
	puts("Now you have to inter some words which need to have spacebars in them\n") ;
	
	getline(cin , str);
	
	cout<<"Hari Bol "<<str ; 
	
	
	//puts("\n Now I will demonstrate you how to take input of arrays of unkown size \n");
	
	
	//vector<int> vec ; 
	
	//int val ; 
	//while(cin >> val){
		//if(val==0) break ; 
		//vec.push_back(val);
	//}
	
	//debug(val);
	
	
	
	
	
	
	

	
	
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
