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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

lli compliment(lli x,lli n)
{
    return n-1-x;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        if(n == 4 && k == 3)
            cout<<"-1\n";
        else
        {
            vector<pair<lli,lli>> vv;
            if(k == n-1)
            {
                vv.push_back({n-1,n-2});
                vv.push_back({n-3,1});
                vv.push_back({2,0});
                for(int i=3; i<n/2; i++)
                    vv.push_back({i,n-i-1});
            }
            else if(k == 0)
            {
                for(int i=0; i<n/2; i++)
                    vv.push_back({i,n-i-1});
            }
            else
            {
                vv.push_back({k,n-1});
                lli cc = compliment(k,n);
                //cout<<"compliment of "<<k<<cc<<"\n";
                vv.push_back({0,cc});

                for(int i=1; i<n/2; i++)
                {
                    if(i != cc && i != k)
                        vv.push_back({i,n-i-1});
                }
            }
            //line_printer(20);
            for(auto i:vv)
                cout<<i.first<<" "<<i.second<<"\n";
            //line_printer(20);
        }
        t--;
    }
    return 0;
}
