#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int maxrange=INT_MAX;
int minrange=INT_MIN;
int dpcalc(vector<int> &arr,int idx,int inc,int dec,vector<vector<vector<int>>> &dp,int t){
	if(dp[idx][inc][dec]!=-1)
		return dp[idx][inc][dec];
	if(idx==t){
		return 0;
	}
	if(arr[idx]>arr[inc]){
		dp[idx][inc][dec]=dpcalc(arr,idx+1,idx,dec,dp,t);
	}
	if(arr[idx]<arr[dec]){
		if(dp[idx][inc][dec]==-1){
			dp[idx][inc][dec]=dpcalc(arr,idx+1,inc,idx,dp,t);
		}
		else{
			dp[idx][inc][dec]=min(dp[idx][inc][dec],dpcalc(arr,idx+1,inc,idx,dp,t));
		}
	}
	
	if(dp[idx][inc][dec]==-1){
		dp[idx][inc][dec]=1+dpcalc(arr,idx+1,inc,dec,dp,t);
	}
	else{
		dp[idx][inc][dec]=min(dp[idx][inc][dec],1+dpcalc(arr,idx+1,inc,dec,dp,t));
	}
	return dp[idx][inc][dec];
	
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t!=-1){
		vector<int> arr(t+2);
		for(int i=0;i<t;i++){
			cin>>arr[i];
		}
		arr[t]=minrange;
		arr[t+1]=maxrange;
		vector<vector<vector<int>>> dp(t+3,vector<vector<int>>(t+3,vector<int>(t+3,-1)));
		cout<<dpcalc(arr,0,t,t+1,dp,t)<<"\n";
		cin>>t;
	}
	return 0;
}
