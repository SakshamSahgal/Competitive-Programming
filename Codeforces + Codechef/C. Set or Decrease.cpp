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

lli sum_btw(lli *ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return ps[r] - ps[l-1];
}

lli calc_x(lli k,lli s,lli sizze)
{

    if( (abs(k - s))%(sizze + 1) == 0)
        return ((k - s)/(sizze + 1));
    else
    {
        if(k >= s)
            return ((k - s)/(sizze + 1));
        else
            return ((k - s)/(sizze + 1) - 1);
    }
}

lli moves_req(lli sizze,lli x,lli a0)
{
    return ( (sizze + max((lli)0,a0 - x)) );
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli prefix_s[n];
        lli sum=0;

        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);
       // cout<<"\n-------------------------\n";
        for(int i=0; i<n; i++)
        {
           // cout<<a[i]<<" ";
            sum += a[i];
            prefix_s[i] = sum;
        }
       // cout<<"\n-------------------------\n";

        if(n == 1)
            cout<<max((a[0] - k),(lli)0)<<"\n";
        else
        {

            if(sum <= k)
                cout<<0<<"\n";
            else
            {
                lli ans =  sum - k;
                for(lli i=n-1,j=1; i>=1; i--,j++)
                {
                    lli x = calc_x(k,sum_btw(prefix_s,1,i-1),j);
                    //cout<<"for size = "<<j<<" sum btw = "<<sum_btw(prefix_s,1,i-1)<<" x = "<<x<<" ";
                    //cout<<"Moves required = "<<moves_req(j,x,a[0])<<"\n";
                    ans = min(ans,moves_req(j,x,a[0]));
                }
                cout<<ans<<"\n";
            }

        }
l:
        t--;
    }
    return 0;
}
