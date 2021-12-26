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
    lli n,m,k;
    cin>>n>>m>>k;
    lli maxi=0;
    lli maxi_i=0;
    lli a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] > maxi)
            {
              maxi = a[i];
            maxi_i = i;
            }

    }
    if(k == m)
    {
        cout<<m*maxi<<"\n";
    }
    else
    {

        lli sec_maxi=0;
        for(int i=0; i<n; i++)
        {
            if(i != maxi_i && a[i] > sec_maxi)
                sec_maxi = a[i];
        }

        lli x = m/(k+1);

        //cout<<"maxi = "<<maxi<<"sec max = "<<sec_maxi<<"\n";

        cout<<(lli)(x*k*maxi + x*sec_maxi + (m%(k+1))*maxi)<<"\n";
    }



    return 0;
}

