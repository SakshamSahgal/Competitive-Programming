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

    lli n,q;
    cin>>n>>q;

    map<pair<lli,lli>,lli> xy;
    lli bad_c = 0;
    for(int i=1; i<=q; i++)
    {
        lli r,c;
        cin>>r>>c;

        if(xy[ {r,c}] == 1)
        {
            xy[ {r,c}] = 0;

            lli x = (r == 1)? 2 : 1;

            if(xy[ {x,c}])
                bad_c--;
            if(xy[ {x,c-1}])
                bad_c--;
            if(xy[ {x,c+1}])
                bad_c--;
        }
        else
        {
            xy[ {r,c}] = 1;

            lli x = (r == 1)? 2 : 1;

            if(xy[ {x,c}])
                bad_c++;
            if(xy[ {x,c-1}])
                bad_c++;
            if(xy[ {x,c+1}])
                bad_c++;
        }

        if(bad_c > 0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }



    return 0;
}
