#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
{
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
		cin>>a[i];

sort(a,a+n,greater<int>());
usi c =0;
for(usi i=0;i<(n-1);i++)
	{
		for(usi j=i+1;j<n;j++)
		{
		    //cout<<a[i]<<" "<<a[j]<<"\n";
			if(a[i]>a[j])
				{
				c++;
				break;
				}
		}

	}
cout<<c<<"\n";
t--;
}

return 0;
}
