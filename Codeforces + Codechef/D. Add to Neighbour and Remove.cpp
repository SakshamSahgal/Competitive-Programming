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

set<lli> factors(lli n)
{
    set<lli> x;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            x.insert(i);
            x.insert((n/i));
        }
    }
    return x;
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
        lli maxx = INT_MIN;
        lli a[n];
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
            maxx = max(maxx,a[i]);
        }
        set<lli> f = factors(sum);
        for(auto i:f)
        {
            if( i >= maxx )
            {
                //cout<<"Trying = "<<i<<"\n";
                lli s=0;
                for(int j=0; j<n; j++)
                {
                    s += a[j];
                    //cout<<"sum = "<<s<<"\n";
                    if(s > i)
                    {
                        //cout<<"failed\n";
                        break;
                    }
                    else if(s == i)
                    {
                        //cout<<"hua\n";
                        s = 0;
                        if(j == n-1)
                        {
                            cout<<n - sum/i<<"\n";
                            goto k;
                        }
                    }
                }
            }
        }

        cout<<n-1<<"\n";

        k:
        t--;
    }
    return 0;
}
