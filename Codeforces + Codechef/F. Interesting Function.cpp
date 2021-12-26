#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli l,r;
        cin>>l>>r;
        lli sum=0;
        int a,b;

        a = l;
        b = r;

        int d=10;
        while( l/d != 0 )
        {
            a+=l/d;
            d*=10;
        }
        d=10;
        while( r/d != 0 )
        {
            b+=r/d;
            d*=10;
        }
        cout<<b-a<<"\n";
        t--;
    }

    return 0;
}

