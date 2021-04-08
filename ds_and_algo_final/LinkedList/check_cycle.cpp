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


class LLNode {
	public : 
		int val ;
		struct LLNode* next ;
		LLNode(int data){
			this->val = data; 
			next = nullptr ; 
		}
};

LLNode* push(LLNode*& tail , int data){
	
	tail->next = new LLNode(data) ;
	tail = tail->next ;
	return tail ; 
}

void print(LLNode *node){
	while(node){
		cout<<node->val<<" ";
		node = node->next ;
	}
}

bool check_cycle(LLNode* node){
	
	LLNode *slow = node ;
	LLNode* fast = node ;
	
	while(fast and fast->next){
		slow = slow->next ;
		fast = fast->next->next ;
		if(slow == fast) return 1 ;
	}
	
	return 0 ;
}




void solve()
{
	
	LLNode* head = new LLNode(0) ;
	LLNode* tail = head ;
	
	
	// 1 -> 2 -> 3 ->5 ->2 
	push(tail , 1);
	LLNode* link =  push(tail , 2);
	push(tail , 3);
	push(tail , 5);
	LLNode* swch =  push(tail , 2);
	
	swch->next = link ; 
	
	
	

	head = head->next ;
	
	//print(head);
	
	bool ans = check_cycle(head);
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
