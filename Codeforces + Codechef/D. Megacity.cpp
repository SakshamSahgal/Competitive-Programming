#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct info
{
lli x;
lli y;
lli p;
};
int main()
{
    //GO_FAST

        lli n,s;
        cin>>n>>s;
        map<long double,info> v;
        for(int i=0;i<n;i++)
        {
            long double x,y,p;
            cin>>x>>y>>p;
            long double dfo = sqrtl(x*x + y*y);
            info ii;
            ii.x = x;
            ii.y = y;
            ii.p = p;
            v[dfo] = ii;
        }


        for(auto i:v)
        {
            //cout<<i.first<<" "<<i.second.x<<" "<<i.second.y<<" "<<i.second.p<<"\n";
            s += i.second.p;
            if(s >= 1000000)
            {
                cout<<setprecision(8)<<i.first<<"\n";
                return 0;
            }
        }

        cout<<"-1\n";
    return 0;
}
