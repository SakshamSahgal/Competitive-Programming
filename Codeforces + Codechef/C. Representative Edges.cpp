#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


lli calc(long double d,lli st,long double *a,lli n)
{
    long double x[n+1];
    x[st] = a[st];
    lli c=0;
    for(int i=st-1,j=1; i>=1; i--,j++)
        x[i] = a[st] - d*j;

    for(int i=st+1,j=1; i<=n; i++,j++)
        x[i] = a[st] + d*j;

    //cout<<"\n------------------------\n";
    for(int i=1; i<=n; i++)
    {
        //cout<<x[i]<<" ";
        if(x[i] != a[i])
            c++;
    }
    //cout<<"\n------------------------\n";
    return c;
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        long double a[n+1];
        for(int i=1; i<=n; i++)
            cin>>a[i];

        if(n == 1)
            cout<<0<<"\n";
        else
        {
            lli ans=INT_MAX;
            for(int i=1; i<=n; i++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    long double d = (a[i] - a[j])/(i-j);
                    ans = min(calc(d,i,a,n),ans);
                }

            }
            cout<<ans<<"\n";
        }

        t--;
    }
    return 0;
}
