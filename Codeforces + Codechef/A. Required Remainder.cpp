#include<iostream>
#define ui unsigned int
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
ui x,y,n;
cin>>x>>y>>n;
if((n-((n/x)*x)>=y))
    {
        cout<<(n/x)*x+y<<"\n";
    }
else
    {
    cout<<(n/x)*x-(x-y)<<"\n";
    }
}

return 0;
}
