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
int t;
cin>>t;
while(t)
    {
    lli a,y,x;
    cin>>a>>y>>x;
    if(a>=y)
        {
        cout<<a*x - (a-y)*x<<"\n";
        }

    else
        {
          cout<<a*x + 1<<"\n";
        }

    t--;
    }

return 0;
}


