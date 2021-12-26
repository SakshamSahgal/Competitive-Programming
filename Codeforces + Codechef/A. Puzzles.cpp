#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

usi n,m;
cin>>n>>m;
usi a[m];
for(usi i=0;i<m;i++)
    cin>>a[i];

sort(a,a+m);
usi diff = INT_MAX;
/*
cout<<"\n-----\n";
for(usi i=0;i<m;i++)
cout<<a[i]<<" ";
cout<<"\n-----\n";
*/
for(usi i=0;i<=(m-n);i++)
    {
        if( (a[i+n-1]-a[i]) < diff)
            diff = (a[i+n-1]-a[i]);

    }
cout<<diff;
return 0;
}
