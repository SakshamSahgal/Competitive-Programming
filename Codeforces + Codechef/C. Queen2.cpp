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
    //GO_FAST
    lli n;
    cin>>n;
    vector<pair<lli,lli>> v(n+1);
    lli rem[n+1] = {0};
    map<lli,vector<lli>> g;
    for(int i=1; i<=n; i++)
    {
        lli p,c;
        cin>>p>>c;
        v[i].first = p;
        v[i].second = c;
        if(p == -1)
            rem[i] = 1;
        else
        {
            if(c == 0) //good
              {
                  rem[p] = 1;
                  rem[i] = 1;
              }
        }
    }



    bool atleast_one_found=0;
    for(int i=1; i<=n; i++)
    {
        if(rem[i] == 0 )
        {
            atleast_one_found = 1;
            cout<<i<<" ";
        }
    }

    if(atleast_one_found == 0)
        cout<<"-1\n";

    return 0;
}
