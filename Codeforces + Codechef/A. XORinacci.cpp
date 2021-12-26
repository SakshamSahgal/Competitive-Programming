#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    unsigned long long int a,b,n;
    cin>>a>>b>>n;
    if(n%3 == 0)
        cout<<a<<"\n";
    else if((n-1)%3 == 0)
        cout<<b<<"\n";
    else
        cout<<(a^b)<<"\n";
    }

return 0;
}
