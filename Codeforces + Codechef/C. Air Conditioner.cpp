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
        lli n,m;
        cin>>n>>m;
        lli mini=m,maxx=m;
        lli a[n][3];
        bool loose=0;
        for(int i=0; i<n; i++)
            cin>>a[i][0]>>a[i][1]>>a[i][2];

        for(int i=0; i<n; i++)
        {
            if( i == 0 )
            {
                mini = m - (a[i][0]);
                maxx = m + (a[i][0]);
            }
            else
            {
                lli time = (a[i][0] - a[i-1][0]);
                mini = max(a[i-1][1],mini) - time;
                maxx = min(a[i-1][2],maxx) + time;
            }
            //cout<<"Min = "<<mini<<" maxx = "<<maxx<<"\n";

            if( a[i][1] > maxx || a[i][2] < mini  )
            {
                cout<<"NO\n";
                loose = 1;
                break;
            }
        }

        if(loose == 0)
            cout<<"YES\n";

        t--;
    }
    return 0;
}
