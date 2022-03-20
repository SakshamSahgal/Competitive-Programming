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



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n];
        lli b[m];
        vector<lli> ord;
        map<lli,lli> id;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            id[a[i]] = i;
        }

        for(int i=0; i<m; i++)
        {
            cin>>b[i];
            ord.push_back(id[b[i]]);
        }

        lli done=0;
        lli i=0;
        lli j=0;
        lli ans=0;
        while(i < ord.size())
        {
            //cout<<i<<" = "<<(2*(ord[i] - done) + 1)<<"\n";
            ans += (2*(ord[i] - done) + 1);
            done++;
            j = i;
            while(j + 1 < ord.size() && ord[j+1] < ord[i])
            {
                j++;
                //cout<<j<<" = "<<1<<"\n";
                ans += 1;
                done++;
            }
            i = j+1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

