#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,x,flag=0,z;
	cin>>t;
	z=t;
	unordered_map<int,int> umap;
	while(t--){
		cin>>x;
		umap[x]++;
		if(x>z)
			flag=1;
	}
	if(umap.size()>2){
		cout<<"-1\n";
	}
	else if(flag==1)
		cout<<"-1\n";
	else if(umap.size()==1){
		if(umap[0].first==0){
			cout<<"0\n";
		}
		else{
			cout<<umap.second+1<<"\n";
		}
	}
	else{
		int check=max(umap[0].second,umap[1].second);
		cout<<check<<"\n";
