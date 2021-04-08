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
		
		LLNode(int data , LLNode* link){
			this->val = data;
			next = link ;
		}
};

void push(LLNode*& tail , int data){
	
	tail->next = new LLNode(data) ;
	tail = tail->next ;
}

LLNode* reverse(LLNode* head){
	
	if(not head or not head->next){
		return head ; 
	}
	
	LLNode* rest = reverse(head->next);
	head->next->next = head;
	head->next = nullptr ;
	
	return rest ;
	
}

void print(LLNode *node){
	while(node){
		cout<<node->val<<" ";
		node = node->next ;
	}
}

LLNode* rev_in_g(LLNode* head , int k){
	
	LLNode* ans = new LLNode(0);
	LLNode* tail = ans ;
	
	LLNode* curr = head ;
	
	while(curr){
		int cnt = 0 ;
		LLNode* prev = nullptr , *next = nullptr ; 
		LLNode* temp = curr; 
		while(cnt<k and curr){
			next = curr->next ;
			curr->next= prev ;
			prev =curr ;
			curr = next ;
			cnt++ ;
		}
		temp->next = curr ;
		tail->next = prev ;
		tail = temp; 
	}
	
	return ans->next ;
}



void solve()
{
	
	LLNode* head = new LLNode(0) ;
	LLNode* tail = head ;
	
	for(int i=1 ; i<15 ; i++){
		push(tail , i);
	}
	head = head->next ;
	int k= 3 ;
	LLNode *ans = rev_in_g(head , k);
	
	print(ans);
	
	
	
	


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
