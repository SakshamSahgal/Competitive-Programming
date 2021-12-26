#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    r1--;
    r2--;
    c1--;
    c2--;

    if(r1 == r2 || c1 == c2)
        cout<<1<<" ";
    else
        cout<<2<<" ";

    if(abs(r1-r2) == abs(c1-c2))
        cout<<"1 ";
    else
    {
        if((r1%2) == (c1%2))
        {
            if(r2%2 == c2%2)
                cout<<2<<" ";
            else
                cout<<0<<" ";
        }
        else
        {
            if(r2%2 == c2%2)
                cout<<0<<" ";
            else
                cout<<2<<" ";
        }
    }

    if(r1 == r2 || c1 == c2)
        cout<<abs(r1-r2) + abs(c1-c2);
    else if( abs(r1-r2) == abs(c1-c2) )
        cout<<abs(r1-r2)<<" ";
    else
        cout<<abs(r1-r2) + abs(c1-c2) - min( abs(r1-r2) , abs(c1-c2) )<<" ";
    return 0;
}
