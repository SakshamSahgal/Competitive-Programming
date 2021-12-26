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

bool is_prime(lli n)
{
    bool flag = 1;
    for(lli i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;

    return flag;
}

bool is_possible(lli *a,lli st, lli k,lli n,lli e)
{
    lli val = a[st];
    // cout<<"val = "<<a[st]<<"\n";
    if(val != 1)
    {
        for(int i=1; i<=k; i++)
        {
           // cout<<"checking at "<< a[(st + i*e)] <<"\n";
            if( a[ (st + i*e) ] != 1 )
                return 0;
        }

        return 1;
    }
    else
    {
        lli not_one=0;
        lli that_val;
        for(int i=1; i<=k; i++)
        {
            if( a[ (st + i*e) ] != 1 )
            {
                not_one++;
                that_val = a[ (st + i*e) ];
            }
        }

        if(k == 0)
            return 1;

        if(not_one == 0 || not_one > 1)
            return 0;
        else
        {
            if(is_prime(that_val) == 1 )
                return 1;
            else
                return 0;
        }
    }
}

lli bs_Ans(lli st,lli ed,lli *a,lli i,lli n,lli e)
{
    lli low = st;
    lli high = ed;
    lli mid = (low+high)/2;
    lli ans=0;
    while(low <= high)
    {
       cout<<" \ntrying for mid = "<<mid<<"\n";
        if(is_possible(a,i,mid,n,e))
        {
           cout<<"Possible\n";
            low = mid+1;
            ans = mid;
        }
        else
        {
            high = mid-1;
            cout<<"Not Possible\n";
        }
        mid = (low+high)/2;
    }

    return ans;
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli ans=0;
        lli n,e;
        cin>>n>>e;
        lli a[n+1];
        bool one=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                one=1;
        }

        if(one == 1)
        {
            for(int i=1; i + e <= n ; i++)
            {
                if( a[i] == 1 || is_prime(a[i]) )
                {
                    lli mini = 0;
                    lli maxx = (n-i)/e;
                    cout<<"i = "<<i<<" min = "<<mini<<" maxx = "<<maxx<<"\n";
                    cout<<"possible with k = "<<bs_Ans(mini,maxx,a,i,n,e)<<"\n";
                    ans += bs_Ans(mini,maxx,a,i,n,e);
                }
            }
        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
