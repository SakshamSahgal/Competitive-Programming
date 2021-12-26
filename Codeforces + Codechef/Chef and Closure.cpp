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
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        int mof = 0;
        int of = 0;
        int zf = 0;
        int other = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if( a[i] == -1)
                mof++;
            else if(a[i] == 1)
                of++;
            else if(a[i] == 0)
                zf++;
            else
                other++;
        }

        if(other > 1)
            cout<<0<<"\n";
        else
        {
            if(other == 1)
            {
                if(mof >= 1)
                    cout<<0<<"\n";
                else
                    cout<<1<<"\n";
            }
            else
            {
                if(mof > 1)
                {
                    if(of >= 1)
                        cout<<1<<"\n";
                    else
                        cout<<0<<"\n";
                }
                else
                    cout<<1<<"\n";
            }
        }
        t--;
    }
    return 0;
}

