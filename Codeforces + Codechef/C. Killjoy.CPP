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
        lli f=0;
        lli sum=0;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            sum += (x - a[i]);
            if(a[i] == x)
                f++;
        }

        if(f == n)
            cout<<0<<"\n";
        else
        {
            if( f > 0 )
                cout<<1<<"\n";
            else
            {
                for(lli i=0; i<n; i++)
                {
                    lli xsum = sum - (x - a[i]);
                    if( a[i] - xsum == x)
                    {
                        cout<<1<<"\n";
                        goto j;
                    }
                }
                cout<<2<<"\n";
            }
        }
        j:
        t--;
    }
    return 0;
}
