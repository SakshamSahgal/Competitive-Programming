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

struct Ride
{
    lli happyness=0;
    lli st;
    lli ed;
};

int main()
{
    GO_FAST
    int t;
    cin>>t;

    for(int o=1; o<=t; o++)
    {
        lli d,n,k;

        cin>>d>>n>>k;

        vector<Ride> vv;

        for(lli i=1; i<=n; i++)
        {
            lli h,st,ed;
            cin>>h>>st>>ed;
            Ride r = {h,st,ed};
            vv.push_back(r);
        }

        lli maxx = 0;
        for(lli i=1; i<=d; i++)
        {
            for(lli j=0;j<n;j++)
                {
                    if()
                }
        }
        //Display();
        m.clear();
        cout<<"Case #"<<o<<": "<<maxx<<"\n";
    }


    return 0;
}
