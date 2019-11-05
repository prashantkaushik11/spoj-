#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int size;
	cin>>size;
	vector<long long int> arr(size),b(size);
	for(long long int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(long long int j=1;j<size;j++){
		if(arr[j]-arr[j-1]<0)
			b[j]=-1;
		else if(arr[j]-arr[j-1]>0)
			b[j]=1;
		else
			b[j]=0;
	}
	long long int sign=0,ans=1;
	for(long long int i=1;i<size;i++){
		if(sign==0&&b[i]!=0){
			ans++;
			sign=b[i];
		}
		else if(sign==1&&b[i]==-1){
			ans++;
			sign=b[i];
		}
		else if(sign==-1&&b[i]==1){
			ans++;
			sign=b[i];
		}
	}
	cout<<ans;
	return 0;
}
