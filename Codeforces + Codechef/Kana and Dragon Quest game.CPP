#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t,n,m;
unsigned int x;
cin>>t;
while(t--)
    {
    cin>>x>>n>>m;
    while(n>0 && x>(10*m))
        {
        n--;
        x = (x/2) + 10;
        }

    if(n>=0 && x<=(10*m))
        cout<<"YES\n";
    else
    cout<<"NO\n";
    }

return 0;
}
