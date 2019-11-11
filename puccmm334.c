#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,flag=0,z;
	long long int x;
	scanf("%d",&t);
	z=t;
	unordered_map<long long int,long long int> umap;
	while(t--){
		scanf("%lld",&x);
		umap[x]++;
		if(x>z)
			flag=1;
	}
	if(umap.size()>2){
		printf("-1\n");
	}
	else if(flag==1)
		printf("-1\n");
	else if(umap.size()==1){
		long long int check=INT_MIN;
		for (auto i : umap) 
        	check=max(check,i.first);
		if(check==0){
			printf("0\n");
		}
		else{
			printf("%lld\n",check+1);
		}
	}
	else{
		long long int check=INT_MIN;
		for (auto i : umap) 
        	check=max(check,i.first);
        printf("%lld",check);
	}
	return 0;
}
