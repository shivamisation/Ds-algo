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

void push(LLNode*& tail , int data){
	
	tail->next = new LLNode(data) ;
	tail = tail->next ;
}

void print(LLNode *node){
	while(node){
		cout<<node->val<<" ";
		node = node->next ;
	}
}

void reverse(LLNode*& head){
	LLNode *curr = head ;
	LLNode* prev = nullptr , *next = nullptr ;
	
	while(curr){
		next = curr->next ;
		curr->next = prev ;
		prev = curr;
		curr = next ;
	}
	
	head = prev ;
}

LLNode* add(LLNode* node){
	int carry = 1 ;
	LLNode* ans = new LLNode(0);
	LLNode* tail = ans ; 
	LLNode* curr = node ;
	int val ;
	
	while(curr or carry){
		if(!curr) val = 0;
		else {
			val = curr->val;
			curr = curr->next ;
		}
		
		int dig = (val + carry)%10 ;
		carry = (val + carry)/10 ;
		
		tail->next = new LLNode(dig) ;
		tail = tail->next ;
	}
	
	return ans->next ;
}

LLNode* add(LLNode* a , LLNode* b){
	LLNode* ans = new LLNode(0) ;
	LLNode* curr = ans;
	int vala , valb; 
	
	int carry = 0 , dig ;
	
	while(a or b or carry){
		if(!a) vala = 0 ;
		else {
			vala = a->val ;
			a = a->next ;
		}
		
		if(!b) valb = 0 ;
		else {
			valb = b->val ;
			b = b->next ; 
		}
		
		dig = (vala + valb + carry)%10 ;
		carry = (vala + valb + carry)/10 ;
		
		curr->next = new LLNode(dig);
		curr = curr->next ;
	}
	
	return ans->next ;
}




void solve()
{
	
	LLNode* head = new LLNode(0) ;
	LLNode* tail = head ;
	
	//push all the data of the linked list here
	
	push(tail , 9);
	push(tail , 9);
	push(tail , 9);
	push(tail , 9);
	

	head = head->next ;
	//print(head);
	
	LLNode* head2 = new LLNode(0) ;
	LLNode* tail2 = head2 ;
	
	push(tail2 , 1);
	//push(tail2 , 9);
	//push(tail2 , 9);
	//push(tail2 , 9);
	
	head2 = head2->next ;
	
	reverse(head);
	reverse(head2);
	
	LLNode* a = add(head , head2) ;
	reverse(a);
	print(a);
	

	


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
