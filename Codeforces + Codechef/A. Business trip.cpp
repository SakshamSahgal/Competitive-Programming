#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
int main()
{
usi k;
cin>>k;
usi a[12];
for(usi i=0;i<12;i++)
    cin>>a[i];
sort(a,a+12,greater<int>());
usi sum = 0;
usi i=0;
if(k == 0 )
    {
    cout<<0<<"\n";
    return 0;
    }
bool possible = 0;
for(;i<12;i++)
    {
    sum+=a[i];
    if(sum>=k)
        {
        possible = 1;
        break;
        }
    }
if(possible == 1)
    {
cout<<i+1<<"\n";
    }
else
    {
    cout<<"-1\n";
    }
return 0;
}
