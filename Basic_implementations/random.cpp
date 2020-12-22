// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
 
#define N 4
 
// A min heap node
struct MinHeapNode
{
	int element; // The element to be stored
	int i; // index of the row from which the element is taken
	int j; // index of the next element to be picked from row
};
 
bool operator>(const MinHeapNode& lhs, const MinHeapNode& rhs)
{
  return lhs.element > rhs.element;
}
void printSorted(int mat[][N])
{
   priority_queue<MinHeapNode,vector<MinHeapNode>,greater<MinHeapNode>> q;
   for(int r=0;r<N;r++)
   {
       MinHeapNode m;
       m.element=mat[r][0];
       m.i=r;
       m.j=1;
       q.push(m);
   }
   for(int count=0;count<N*N;count++)
   {
 
   MinHeapNode m=q.top();
   q.pop();
   cout<<m.element<<" ";
   if (m.j < N)
        {
            m.element = mat[m.i][m.j];
            m.j += 1;
        }
        // If root was the last element of its array
   else m.element =  INT_MAX; //INT_MAX is for infinite
 
        // Replace root with next element of array
   q.push(m);
   }
}
 
 
 
// driver program to test above function
int main()
{
int mat[N][N] = { {10, 20, 30, 40},
					{15, 25, 35, 45},
					{27, 29, 37, 48},
					{32, 33, 39, 50},
				};
printSorted(mat);
return 0;
}
 
 
