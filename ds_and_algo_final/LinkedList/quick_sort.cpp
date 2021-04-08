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
	Node* node = new Node() ;
	node->data = x ;
	node->next = nullptr ;
	
	if(head == nullptr){
		*head = node ;
	}
	else {
		Node* curr = *head  ;
		while(curr and curr->next) curr = curr->next ;
		curr->next = node ;
		*head = node ;
	}
}

void print(Node* head){
	while(head){
		cout<<head->data<<"\n" ;
		head = head->next ;
	}
}



void solve()
{
	Node* head = nullptr ;
	push(&head , 9);
	push(&head , 8);
	push(&head , 7);
	push(&head , 6);
	push(&head , 5);
	push(&head , 2);
	push(&head , 1);
	push(&head , 6);
	push(&head , 2);
	
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
