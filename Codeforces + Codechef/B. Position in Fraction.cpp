#include<iostream>
#include<algorithm>
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
    lli a,b,c;
    cin>>a>>b>>c;
    lli counter=0;
    lli k=0;

    if(a%b == 0)
    {
        if(c==0)
            cout<<"1\n";
        else
            cout<<"-1\n";
    }
    else
    {

y:
        a = a%b;
x:
        if(a < b)
        {
           if(k==0)
           {
               cout<<".";
                k++;
           }
           else
           {
               cout<<"0";
               k++;
           }
            a*=10;
            goto x;
        }
        //cout<<"digit no = "<<k<<" = "<<(a/b)<<"\n";
        cout<<(a/b);

       /* if((a/b) == c)
        {
            cout<<k<<"\n";
            return 0;
        }
        if(k>10 || (a/b) == 0)
        {
            cout<<"-1\n";

        }
        */
        k++;
        goto y;

    }

    return 0;
}
