#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int calcRoute(vector<vector<int>> &dp,int size1,int size2,int x,int y,vector<int> &temp,vector<int> &agnes){
	if(dp[x][y]!=-1)
		return dp[x][y];
	else if(size1==0||size2==0){
		return dp[x][y]=0;
	}
	if(agnes[x-1]==temp[y-1])
		return dp[x][y]=1+calcRoute(dp,size1,size2,x-1,y-1,temp,route);
	return dp[x][y]=max(calcRoute(dp,size1,size2,x-1,y,temp,route),calcRoute(dp,size1,size2,x,y-1,temp,route));
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		vector<int> agnes;
		int entry,nRoutes;
		cin>>entry;
		int ans=INT_MIN;
		while(entry!=0){
			agnes.push_back(entry);
			cin>>entry;
		}
		cin>>nRoutes;
		while(nRoutes!=0){
			vector<int> temp;
			temp.push_back(nRoutes);
			cin>>entry;
			while(entry!=0){
				temp.push_back(entry);
				cin>>entry;
			}
			int size1=agnes.size(),size2=temp.size();
			vector<vector<int>> dp(size1+1,vector<int>(size2+1,-1));
			int ans=max(ans,calcRoute(dp,size1,size2,size1,size2,temp,ages));
			cin>>nRoutes;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
