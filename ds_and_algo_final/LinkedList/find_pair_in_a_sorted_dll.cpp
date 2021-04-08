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

void push(Node** head_ref , int x){
	Node* node = new Node() ;
	node->data = x ;
	if(*head_ref){
		(*head_ref)->next= node  ;
	}
	node->prev = *head_ref ;
	node->next = nullptr; 
	
	*head_ref = node ;
}

void print(Node* node){
	while(node){
		cout<<node->data<<" ";
		node = node->next ;
	}
}

void reverse(Node** node){
	Node* curr = *node ;
	Node* prev = nullptr ;
	
	while(curr){
		prev = curr->prev ;
		curr->prev = curr->next ;
		curr->next = prev ;
		curr = curr->prev ;
	}
	
	(*node) = prev->prev ;
}

bool pair_sum(Node* head , int x){
	Node* first = head ;
	Node* second = head;
	while(second->next!=nullptr) second = second->next ;
	bool ok = false ;
	
	while(first and second and first!=second and second->next!=first){
		
		debug(first->data , second->data);
		
		if(first->data + second->data == x){
			ok = true ;
			debug(first->data , second->data);
			first = first->next ;
			second = second->prev ;
		}
		
		else{
			if(first->data + second->data < x){
				first = first->next ;
			}
			else if(first->data + second->data > x){
				second = second->prev ;
			}
		}
	}
	
	return ok ; 
}


void solve()
{
	Node* head = nullptr ;
	
	// remember the nodes must be arranged in a sorted order 
	insert(&head, 10);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 2);
    insert(&head, 2);
    int x = 4;
 
   cout<< pair_sum(head, x);

	
	// your functions here
	
	//reverse(&head); 
	
	//print(head);


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
