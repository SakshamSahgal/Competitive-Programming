#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Eular_GCD(lli a,lli b)
{
    lli temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else if(a>b)
        return a;
    else
        return b;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli a;
        lli b;
        cin>>a>>b;
        if(a == b)
            cout<<0<<" "<<0<<"\n";
        else
        {
            lli x = Eular_GCD(a,b);
            lli y;
            lli z;
            if(a > b)
            {
                y = Eular_GCD(a-b,0);
                cout<<max(x,y)<<" ";
                if(x >= y)
                    cout<<0<<"\n";
                else
                    cout<<Eular_GCD(x,y)<<"\n";

            }

            else
            {
                y = Eular_GCD(0,b-a);
                cout<<max(x,y)<<" ";
                if(x >= y)
                    cout<<0<<"\n";
                else
                    cout<<Eular_GCD(x,y)<<"\n";
            }
        }

        t--;
    }

    return 0;
}
