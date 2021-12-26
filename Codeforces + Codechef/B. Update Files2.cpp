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
        lli n,k;
        cin>>n>>k;
        lli maxx;
        lli tt;
        for(tt=0;;)
        {
            maxx = pow(2,tt);
            //cout<<"tt = "<<tt<<" maxx = "<<maxx<<"\n";
            if(n <= maxx)
            {
                cout<<tt<<"\n";
                goto l;
            }
            else
            {
                lli next_req = pow(2,tt);
                if(k >= next_req)
                    tt++;
                else
                    break;

            }
        }

        if ( (n - maxx)%k == 0 )
            cout<<(n-maxx)/k + tt<<"\n";
        else
            cout<<(n-maxx)/k + tt + 1<<"\n";

l:
        t--;
    }
    return 0;
}
