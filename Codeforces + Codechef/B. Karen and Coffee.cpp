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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    //GO_FAST

        lli n,k,q;
        cin>>n>>k>>q;
        lli cc[200002]={0};
        for(lli i=0;i<n;i++)
        {
            lli l,r;
            cin>>l>>r;
            cc[l]++;
            cc[r+1]--;
        }
        lli sum=0;
        for(int i=0;i<200002;i++)
        {
            sum += cc[i];
            cc[i] = sum;
        }

        vector<lli> ps;
        sum=0;
        for(int i=0;i<200002;i++)
        {
            if(cc[i] >= k)
                sum++;
            ps.push_back(sum);
        }
        for(int i=0;i<q;i++)
        {
            lli a,b;
            cin>>a>>b;
            cout<<sum_btw(ps,a,b)<<"\n";
        }

    return 0;
}
