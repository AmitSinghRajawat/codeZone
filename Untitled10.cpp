#include<iostream>
#include<vector>
using namespace std;
int main(){
	int T,N,K,i,j,count,a;
	cin>>T;
	i=0;
	while(i++<T){
	cin>>N;
	cin>>K;
		j=0;
		count=0;
		while(j++<N){
			
		cin>>a;
			if(a<1){
				count++;
			}
		}
		if(count<K){
		cout<<"YES";
		}
		else
		cout<<"NO";
	}
	return 0;
}