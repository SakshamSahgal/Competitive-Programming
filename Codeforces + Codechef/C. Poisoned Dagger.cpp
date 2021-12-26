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

lli possible(lli *a,lli n,lli k)
{
    lli d = 0;
    for(int i=0; i<n; i++)
    {
        if(i != 0)
        {
            if(i != n-1)
            {
                if( (a[i-1] + k - 1) >= a[i])
                    d += min(k-1,a[i+1] - a[i]);
                else
                    d += min(k,a[i+1]-a[i]+1);
            }
            else
                if( (a[i-1] + k - 1) >= a[i])
                    d += k-1;
                else
                    d += k;
        }
        else
            d += min(k,a[i+1]-a[i]+1);
    }
    return d;
}

int main()
{
    GO_FAST



    int t;
    cin>>t;
    while(t)
    {
        lli n,h;
        cin>>n>>h;
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli low = 1;
        lli high = h + 2000;
        lli ans = h;
        while(low <= high)
        {
            lli mid = (low+high)/2;
            //cout<<"\ntrying "<<mid<<" = "<<possible(a,n,mid)<<"\n";
            if(possible(a,n,mid) >= h)
            {
                ans = mid;
                high = mid-1;
                //cout<<"possible  since damage = "<<possible(a,n,mid)<<"\n";
            }
            else
                low = mid+1;
        }

        cout<<min(ans,h)<<"\n";
        t--;
    }
    return 0;
}
