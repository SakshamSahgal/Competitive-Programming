#include<iostream>
#include<cmath>
using namespace std;
int main()
{
float t,n,x,countit = 0;
cin>>t;
while(t--)
    {
    cin>>n>>x;
    if(n<=2)
        {
        countit = 1;
        }
    else
        {
        countit = ceil((n-2)/x) + 1;
        }
        cout<<countit<<"\n";
    }
return 0;
}
