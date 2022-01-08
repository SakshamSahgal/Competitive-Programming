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

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        lli a[n];
        lli dp[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);
        lli limit = n;
        for(lli i=n-1,j=1; i>=0; i--,j++)
        {
            if(a[i] < x)
                break;
            else
            {
                dp[i] = j;
                limit--;
            }
        }
        limit--;
        for(lli i=limit; i>=0; i--)
        {
            lli y = ceil( (x*1.0)/(a[i]*1.0) );
            //cout<<"i = "<<i<<"y = "<<y<<"\n";
            if(i + y - 1 >  limit )
            {
                if(limit+1 > n-1)
                    dp[i] = 0;
                else
                    dp[i] = dp[limit+1];
            }
            else
            {
                if(i+y > n-1)
                    dp[i] = 1;
                else
                    dp[i] = dp[i+y] + 1;
            }

        }
        //array_printer(a,n);
        //array_printer(dp,n);
        lli ans = 0;
        for(int i=0;i<n;i++)
            ans = max(dp[i],ans);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
