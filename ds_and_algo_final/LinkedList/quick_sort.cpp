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
};

void push(Node** head , int x){
	
	Node* new_node = new Node ;
	new_node->data = x ;
	new_node->next = nullptr ;
	
	
	if(*head == nullptr){
		*head = new_node ;
	}
	
	else{
		Node* curr = *head ; 
		while(curr and curr->next) curr = curr->next ; 
		curr->next = new_node ;
	}

}

void print(Node* head){
	while(head){
		cout<<head->data<<"\n" ;
		head = head->next ;
	}
}

void swap(Node* &a , Node* &b){
	int temp = a->data ;
	a->data = b->data ;
	b->data = temp ; 
}


Node* part(Node* lo , Node* hi , Node** prev){
	Node* i = nullptr ;
	Node* j = lo ;
	int pivot = hi->data ;
	
	while(j!=hi){
		if(j->data<=pivot){
			*prev = i ;
			i = (i==nullptr) ? lo : i->next ;
			swap(i,j);
		}
		j = j->next ;
	}
	
	*prev = i ;
	i = (i==nullptr)?lo : i->next ;
	swap(i,j);
	return i ;
}


void q_sort(Node* lo , Node* hi){
	if(lo and hi and lo!=hi and hi->next!=lo){
		Node* prev = nullptr ;
		Node* pi= part(lo , hi , &prev);
		q_sort(lo , prev);
		q_sort(pi , hi);
	}
}



void solve()
{
	Node* head = nullptr ;
	
	push(&head , 9);
	push(&head , 8);
	push(&head , 5);
	push(&head , 7);
	push(&head , 3); 
	push(&head , 9);
	push(&head , 1);
	
	Node* curr = head ;
	while(curr and curr->next) curr = curr->next ;
	
	//cout<<curr->data ;  
	
	q_sort(head , curr);
	
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
