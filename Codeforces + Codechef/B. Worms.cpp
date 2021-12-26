#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
int a[n];
vector <int> b;
b.push_back(0);
int j=1,c=1;
for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int k=1;k<=a[i];j++,k++)
			{
				b.push_back(c);
				//cout<<j<<" ";
				//cout<<"\n";
			}
		c++;
	}
int m;
cin>>m;
int q;
for(int i=0;i<m;i++)
	{
		cin>>q;
		cout<<b[q]<<"\n";
	}
return 0;
}

