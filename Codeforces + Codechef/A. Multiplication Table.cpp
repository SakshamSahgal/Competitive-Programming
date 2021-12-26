#include<iostream>
#include<cmath>
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
ulli n,x;
cin>>n>>x;
if(x == 1)
    cout<<"1\n";
else if(x>(n*n))
 cout<<"0\n";
else
    {
        ulli counter=0;
        for(ulli i=1;i<=(min(x,n));i++)
            {
                    if( (x%i == 0) && (x/i)<=n )
                        counter++;
            }
    cout<<counter<<"\n";
    }


return 0;
}
