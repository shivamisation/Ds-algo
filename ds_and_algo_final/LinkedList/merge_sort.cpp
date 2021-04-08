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

LLNode* merge2(LLNode* a , LLNode* b){
	
	LLNode* dummy = new LLNode(0) ;
	LLNode* curr = dummy ;
	
	while(a and b){
		if(a->val < b->val){
			curr->next = a;
			a = a->next ;
			curr = curr->next ;
			curr->next = nullptr;
		}
		else {
			curr->next = b;
			b = b->next ;
			curr = curr->next ;
			curr->next = nullptr ;
		}
	}
	
	while(a){
		curr->next = a;
		a = a->next ;
		curr = curr->next ;
		curr->next = nullptr ;
	}
	
	while(b){
		curr->next = b ;
		b = b->next ;
		curr = curr->next ;
		curr->next = nullptr ;
	}
	
	return dummy->next ;
}

LLNode* merge1(LLNode* a , LLNode* b){
	
	// This is the recursive version of the mergeing technique 
	
	LLNode* res = nullptr ;
	
	if(a==nullptr) return b; 
	if(b==nullptr) return a ;
	
	if(a->val <= b->val){
		res = a ;
		res->next = merge1(a->next , b);
	}
	else {
		res = b;
		res->next = merge1(a , b->next);
	}
	
	return res ;
}

LLNode* merge_sort(LLNode* node){
	
	if(!node or !node->next) return node ;
	
	LLNode* fast = node ;
	LLNode* slow = node ;
	LLNode* prev = nullptr ;
	
	while(fast and fast->next){
		prev = slow ;
		slow = slow->next ;
		fast = fast->next->next ;
	}
	
	prev->next= nullptr ;
	
	LLNode* a = merge_sort(node);
	LLNode* b = merge_sort(slow);
	
	return merge2(a , b);
	
}


void solve()
{
	
	// here the merging has been implemented using two techniques 
	// recursive and iterative , both has to be learned 
	
	LLNode* head = new LLNode(0) ;
	LLNode* tail = head ;
	
	//push all the data of the linked list here
	
	push(tail , 9);
	push(tail , 1);
	push(tail , 3);
	push(tail , 91);
	

	head = head->next ;
	//print(head);
	
	LLNode* sorted = merge_sort(head);
	
	print(sorted);
	


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
 
