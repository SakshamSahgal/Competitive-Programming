#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void array_printer(int a[],int n)
{
    //cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    //cout<<"\n----------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    int n,d,l;
    cin>>n>>d>>l;
    int a[n+1];
    int noo = (n&1)*(n/2+1) + (!(n&1))*(n/2);
    int noe = n/2;
    //cout<<"no of odd & even = "<<no_of_odd<<" "<<no_of_even<<"\n";

    int max_d = noo*l - noe;
    int min_d = noo - noe*l;

    if( d>max_d || d<min_d )
        cout<<"-1\n";
    else
    {
        if(d > 0)
        {
            int min_soo = d+noe;
            if(min_soo <= (noo*l) && min_soo >= noo)
            {
                for(int i=1; i<=n; i++)
                    a[i] = 1;

                int req = d + noe - noo;

                if(req > 0)
                {
                    for(int i=0,j=1; i<(noo); i++,j+=2)
                    {
                        if( (l-a[j]) <= req)
                        {
                            req -= (l-a[j]);
                            a[j] = l;
                        }
                        else
                        {
                            a[j] += req;
                            req = 0;
                            break;
                        }

                        if(req == 0)
                            break;
                    }

                    array_printer(a,n);
                }
                else
                    array_printer(a,n);


            }
            else
                cout<<"-1\n";
        }
        else if(d<0)
        {
            int min_soe = noo - d;
            if(min_soe <= noe*l && min_soe >= noe)
            {
                for(int i=1; i<=n; i++)
                    a[i] = 1;

                int req = (noo - d) - noe;

                if(req > 0)
                {
                    for(int i=0,j=2; i<noe; i++,j+=2)
                    {
                        if( (l- a[j]) <= req)
                        {
                            req -= (l- a[j]);
                            a[j] = l;
                        }
                        else
                        {
                            a[j] += req;
                            req = 0;
                            break;
                        }
                        if(req == 0)
                            break;
                    }

                    array_printer(a,n);
                }
                else
                    array_printer(a,n);


            }
            else
                cout<<"-1\n";
        }
        else
        {
            if(noo == noe)
            {
                for(int i=1;i<=n;i++)
                    cout<<1<<" ";
            }
            else
            {
                if(l>=2)
                {
                    for(int i=1;i<=n;i++)
                        a[i] = 1;
                    a[2] = 2;

                    array_printer(a,n);
                }
                else
                    cout<<"-1\n";
            }

        }


    }

    return 0;
}
