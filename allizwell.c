#include <bits/stdc++.h>
using namespace std;
int isvalid(int i,int j,int x,int y){
	if(i>=x||i<0||j<0||j>=y)
		return 0;
	return 1;
}
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
void dfs(int *flag,string str,string test,int i,int j,int r,int c,vector<vector<char>> &matrix,vector<vector<int>> &visited){
	if(*flag==1)
		return;
	int s1=test.size();
	if(s1>str.size()){
		visited[i][j]=0;
		return;
	}
	if(str[s1]!=matrix[i][j]){
		visited[i][j]=0;
		return;
	}
	test=test+str[s1];
	if(test==str){
		*flag=1;
		visited[i][j]=0;
		return;
	}
	for(int k=0;k<8;k++){
		if(isvalid(i+dx[k],j+dy[k],r,c)&&(visited[i+dx[k]][j+dy[k]]==0)){
			visited[i+dx[k]][j+dy[k]]=1;
			dfs(flag,str,test,i+dx[k],j+dy[k],r,c,matrix,visited);
		}
	}
	visited[i][j]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		vector<vector<char>> matrix(r,vector<char>(c));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>matrix[i][j];
			}
		}
		string str="ALLIZZWELL";
		int flag=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(matrix[i][j]=='A'){
					vector<vector<int>> visited(r,vector<int>(c,0));
					visited[i][j]=1;
					dfs(&flag,str,"",i,j,r,c,matrix,visited);
				}
				if(flag==1)
					break;
			}
				if(flag==1)
					break;
		}
		if(flag==1){
			cout<<"YES\n";
		}
		else
			cout<<"NO\n";
	}
	return 0;
}
