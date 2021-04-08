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

LLNode* merge(LLNode* a , LLNode* b){
	
	LLNode* result = nullptr ;
	if(a == nullptr) return b ;
	if(b == nullptr) return a ;
	
	if(a->val <= b->val){
		result = a ;
		result->next = merge(a->next , b);
	}
	
	else {
		result = b ;
		result->next = merge(a , b->next);
	}
	
	return result ;	
}



void merge_sort(LLNode** head){
	LLNode* node = *head ;
	
	if(node == nullptr or node->next == nullptr) return  ;
	
	LLNode* fast = node ;
	LLNode* slow = node ;
	LLNode* prev = nullptr ;
	
	while(fast and fast->next){
		prev = slow ;
		slow = slow->next ;
		fast = fast->next->next ;
	}
	prev->next = nullptr ;
	
	merge_sort(&node);
	merge_sort(&slow);
	
	*head = merge(node , slow);	
}

void solve()
{
	LLNode* head = new LLNode(0) ;
	LLNode* tail = head ;
	
	push(tail , 9);
	push(tail , 8);
	push(tail , 7);
	push(tail , 6);
	push(tail , 5);
	push(tail , 2);
	push(tail , 1);

	head = head->next ;
	
	merge_sort(&head);
	print(head);

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
