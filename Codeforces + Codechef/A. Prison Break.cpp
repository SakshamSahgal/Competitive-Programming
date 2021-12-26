#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
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
    int a,b;
    cin>>a>>b;
    if(a == 1)
    cout<<b<<"\n";
    else if(b == 1)
    cout<<a<<"\n";
    else
        cout<<(a*b)<<"\n";
    t--;
    }
return 0;
}

