#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
lli nod(lli a)
{
    lli nod=0;
    while(a!=0)
    {
        nod++;
        a/=10;
    }
    return nod;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    lli n;
    cin>>n;
    if(n<2050)
        cout<<"-1\n";
    else
        {
            if(n%2050 == 0)
                {
                    lli x = n/2050;
                    lli numd;
                    lli c=0;
                    lli temp;
                    y:
                    numd = nod(x);
                    temp = (x/(pow(10,numd-1)));
                    c+= temp;
                    x-=  temp*pow(10,numd-1);
                    if(x>0)
                        goto y;

                    cout<<c<<"\n";
                }
            else
                cout<<"-1\n";
        }

    t--;
    }

return 0;
}

