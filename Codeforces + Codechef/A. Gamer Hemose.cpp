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
        lli n,h;
        cin>>n>>h;
        lli a[n];
        lli maxx = INT_MIN;
        lli maxx_index=0;
        lli maxx2=INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] > maxx)
            {
                maxx = a[i];
                maxx_index = i;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(i != maxx_index)
                maxx2 = max(a[i],maxx2);
        }

        //cout<<maxx<<" "<<maxx2<<"\n";
        lli m1,m2;

        if( (h+maxx2)%(maxx + maxx2) == 0 )
            m1 = (h+maxx2)/(maxx + maxx2);
        else
            m1 = (h+maxx2)/(maxx + maxx2) + 1;

        m1 = 2*m1 - 1;


        if( h%(maxx + maxx2) == 0)
            m2 = (h/(maxx + maxx2))*2;
        else
            m2 = (h/(maxx + maxx2) + 1)*2;

        cout<<min(m1,m2)<<"\n";
        t--;
    }
    return 0;
}
