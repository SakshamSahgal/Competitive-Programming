#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    ulli y,k,n;
    cin>>y>>k>>n;
    if(n<=y)
        cout<<"-1\n";
    else if(k == 1)
    {
        for(ulli x=1; x<=(n-y); x++)
            printf("%d ",x);
        cout<<"\n";
    }
    else
    {
        ulli x = (((y/k)+1)*k - y);

        if(x>(n-y))
        {
            cout<<"-1\n";
        }
        else
        {
            for(; x<=(n-y); x+=k)
            {
            printf("%d ",x);
            }

        }
        cout<<"\n";
    }
    return 0;
}
