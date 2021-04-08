#include <bits/stdc++.h>
using namespace std;
string str="GEEKS";
char a[][10] = {
            {'D','D','D','G','D','D'},
            {'B','B','D','E','B','S'},
            {'B','S','K','E','B','K'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','G'}
           };
int n=6,m=6;
int dfs(int i,int j,int idx){
    if(idx==str.length()-1&&a[i][j]==str[idx]) return 1;
    int ans=0;
    if(a[i][j]==str[idx]){
        if(j<m)
            ans+=dfs(i,j+1,idx+1);
        if(j>0)
            ans+=dfs(i,j-1,idx+1);
        if(i>0)
            ans+=dfs(i-1,j,idx+1);
        if(i<n)
            ans+=dfs(i+1,j,idx+1);
    }
    return ans;
}
int main() {
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dfs(i,j,0);
        }
    }
	cout<<ans;
	return 0;
}
