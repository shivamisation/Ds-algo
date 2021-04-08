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

class Node{
	public :
	int data ;
	Node* next ;
	Node* prev ;
};

void insert(Node** head_ref , int new_data ){
	Node* node = new Node() ;
	node->data = new_data ;
	node->prev = nullptr ;
	node->next = *head_ref ;
	
	if(*head_ref!=nullptr) {
		(*head_ref)-> prev = node ;
	}
	
	*head_ref = node ;
}

void push(Node **head , int x){
	Node* node = new Node() ;
	
	if(*head == nullptr){
		(*head) = node ;
		(*head)->prev = nullptr ;
		(*head)->next = nullptr ;
		(*head)->data = x ;
	}
	else {
		Node *tail = *head ;
		while(tail and tail->next){
			tail = tail->next ;
		}
		tail->next = node ;
		node->prev = tail ;
		node->next= nullptr ;
		node->data = x ;
	}
}

void print(Node* node){
	while(node){
		cout<<node->data<<" ";
		node = node->next ;
	}
}



void solve()
{
	Node* head = nullptr ;
	insert(&head, 8);
    insert(&head, 56);
    insert(&head, 12);
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 3);
    
    int k = 2 ;
    print(head);
    nl ;
    head = sort_k_sorted(head , k);
    
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
