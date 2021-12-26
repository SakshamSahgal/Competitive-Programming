#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
ulli GCD_Eulid(ulli a,ulli b)
{
    x:
    ulli temp = b;
    b = a%b;
    a = temp;
    if(b==0)
        return a;
    else
        goto x;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ulli r,l;
cin>>l>>r;
//cout<<"\n"<<GCD_Eulid(r,l)<<"\n";
if( (r-l+1)<=2 )
    cout<<"-1\n";
else
    {
    for(ulli i=l;i<=(r-2);i++)
        {
        for(ulli j=i+1;j<=(r-1);j++)
            {

                if( GCD_Eulid(j,i) == 1 )
                    {
                        for(ulli k = j+1 ;k<=r;k++)
                            {
                            if(GCD_Eulid(k,j) == 1 && GCD_Eulid(k,i) != 1 )
                                {
                                cout<<i<<" "<<j<<" "<<k<<"\n";
                                goto x;
                                }

                            }

                    }

            }

        }

    cout<<"-1\n";
    x:
    l=l;
    }


return 0;
}
