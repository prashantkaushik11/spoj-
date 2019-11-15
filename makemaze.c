#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int isvalid(int i,int j,int x,int y){
	if(i<0||i>=x||j<0||j>=y)
		return 0;
		return 1;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>n>>m;
		vector<vector<char>> matrix(n,vector<char>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>matrix[i][j];
			}
		}
		int dx[]={1,0,0,-1};
		int dy[]={0,1,-1,0};
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((i==0||j==0||i==n-1||j==m-1)&&(matrix[i][j]='.')){
					queue<pair<int,int>> q;
					q.push({i,j});
					vector<vector<int>> visited(n,vector<int>(m,0));
					int isSide=0,moreExit=0;
					visited[i][j]=1;
					while(!q.empty()){
						pair<int,int> a=q.front();
						q.pop();
						int fi=a.first,se=a.second;
						if((fi==0||se==0||fi==n-1||se==m-1)){
							if(isSide==0){
								isSide=1;
							}
							else if(isSide==1){
								moreExit=1;
								break;
							}
						}
						for(int k=0;k<4;k++){
							if(isvalid(fi+dx[k],se+dy[k],n,m)&&(visited[fi+dx[k]][se+dy[k]]==0)){
								visited[fi+dx[k]][se+dy[k]]=1;
								q.push({fi+dx[k],se+dy[k]});
							}
						}
					}
					if(isSide==1&&moreExit==0){
						flag=1;break;
					}
				}
				
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			cout<<"valid\n";
		else
			cout<<"invalid\n";
	}
	return 0;
}
