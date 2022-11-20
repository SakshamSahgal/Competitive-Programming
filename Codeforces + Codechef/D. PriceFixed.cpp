#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

bool comp(pll a,pll b)
{
    if(a.second == b.second)
        return (a.first < b.first);
    else
        return (a.second < b.second);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    vector<pll> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end(),comp);

    //for(auto i:v)
       // cout<<i.first<<" "<<i.second<<"\n";

    deque<pll> dq;
    lli ans=0;
    for(auto i:v)
        dq.push_back({i.first,i.second});

    lli taken = 0;
    while(dq.size())
    {
        lli rem_target = dq.front().second - taken;
        //cout<<"cur target = "<<rem_target<<"\n";
        while(dq.size() && rem_target > 0)
        {
            ans += 2*min(rem_target,dq.back().first);
            taken += min(rem_target,dq.back().first);
            //cout<<"taking = "<<min(rem_target,dq.back().first)<<"\n";
            if( rem_target >= dq.back().first )
            {
                rem_target -= dq.back().first;
                dq.pop_back();
            }
            else
            {
                dq.back().first -= rem_target;
                rem_target = 0;
            }
        }

        if(dq.size())
        {
            ans += dq.front().first;
            taken += dq.front().first;
            dq.pop_front();
        }
    }
    cout<<ans<<"\n";
    return 0;
}

