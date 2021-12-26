#include<iostream>
#define ll long long int
using namespace std;
const int mx=1e7+1;
	ll prime[mx+1];
int main(){

	prime[1]=0;prime[0]=0;
	for(int i=2;i<=mx;i++){
		prime[i]=1;
	}
	for(int i=2;i<=mx;i++){
		if(i*i>mx){
			break;
		}
		if(prime[i]==1){
			for(int j=i*i;j<=mx;j=j+i){
				prime[j]=0;
			}
		}
	}
	for(int i=2;i<=mx;i++){
		prime[i]+=prime[i-1];
		//cout<<prime[i]<<" ";

	}
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==2){
			cout<<1<<endl;
		}else if(n==3){
			cout<<2<<endl;
		}else{
		ll ans=prime[n]-prime[n/2];
		cout<<ans+1<<endl;}
	}
}
