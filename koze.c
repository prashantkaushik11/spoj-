#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int m,n;
	cin>>n>>m;
	vector<vector<char>> matrix(n,vector<char>(m,'0'));
	vector<vector<int>> visited(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];		
		}
	}
	queue<pair<int,int>> q;
	int countWolves,countSheep,finalWolve=0,finalSheep=0;
	int dx[]={1,0,-1,0};
	int dy[]={0,1,0,-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0){
				visited[i][j]=1;
				q.push_back({i,j});
				countWolves=0;
				countsheep=0;
				while(!q.empty()){
					pair<int,int> a=q.front();
					int x=a.first;
					int y=a.second;
					if(matrix[i][j]=='v')
						countWolves++;
					if(matrix[i][j]=='k')
						countSheep++;
					for(int k=0;k<3;k++){
						if(isvalid(n,m,x+dx[k],y+dy[k])&&(matrix[x+dx[k]][y+dy[k]]!='#')){
							q.push_back({x+dx[k],y+dy[k]});
						}
					}
				}
				if(countSheep>countWolves){
					finalSheep+=countSheep;
				}
				else{
					finalWolve+=countWolves;
				}
			}
		}
		
	}
	cout<<finalSheep<<" "<<finalWolve;
	return 0;
}
