#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ulli a,b,m=0;
cin>>a>>b;
x:
if(a==b)
    {
    m+=1;
    goto y;
    }
else if(a>b)
    {
    m+=(a/b);
    a -= (a/b)*b;
    if(a == 0)
        goto y;
    goto x;
    }
else
    {
    m+=(b/a);
    b -= (b/a)*a;
    if(b == 0)
        goto y;
    goto x;
    }
y:
cout<<m<<"\n";
return 0;
}
