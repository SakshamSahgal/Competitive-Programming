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

lli can_fit(lli len,lli a)
{
    return (len+1)/(a+1);
}


int main()
{
        GO_FAST

        lli n,k,a;
        cin>>n>>k>>a;
        vector<pair<lli,lli>> v(n+2);
        lli sz;
        cin>>sz;
        lli arr[sz];
        set<lli> cuts;
        cuts.insert(0);
        cuts.insert(n+1);

        for(int i=0;i<sz;i++)
            cin>>arr[i];
        lli tot = 0;
        for(int i=0;i<sz;i++)
        {
            auto just_bada = cuts.lower_bound(arr[i]);
            auto just_chota = cuts.upper_bound(arr[i]);
            just_chota--;
            lli peeche = (*just_chota);
            lli aage = (*just_bada);
            //cout<<"for arr[i] = "<<arr[i]<<" "<<"peeche = "<<peeche<<" aage = "<<aage<<" ";
            lli pf = can_fit(arr[i] - peeche - 1,a);
            lli af = can_fit(aage - arr[i] - 1,a);
            //cout<<"can fit = "<<pf<<" "<<af<<" \n";
            tot = tot - v[peeche].second + pf + af;
            if(tot >= k)
            {
                //cout<<" can fit \n";
                v[peeche].second = pf;
                v[arr[i]].first = pf;
                v[arr[i]].second = af;
                v[aage].first = af;
                cuts.insert(arr[i]);
            }
            else
            {
                cout<<i+1<<"\n";
                return 0;
            }
        }
    cout<<"-1\n";
    return 0;
}

