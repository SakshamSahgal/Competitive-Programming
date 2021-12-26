#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
{
int main()
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
usi n;
cin>>n;
usi a[n];
usi s=0;
usi me = 0;
usi c = 0;
for(usi i=0;i<n;i++)
{
    cin>>a[i];
    s+=a[i];
}
sort(a,a+n,greater<int>());
for(usi i=0;i<n;i++)
    {
    c++;
    me+=a[i];
    if(me>(s-me))
        break;
    }
cout<<c;
return 0;
}
