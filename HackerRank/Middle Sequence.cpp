#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_map>
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


lli max_len(vector<lli> &a1,vector<lli> &a2)
{
    unordered_map<lli, lli> f;

    for (lli i = 0; i < a1.size(); i++) //dist
        f[a1[i]] = i + 1;

    vector<lli> temp;

    for (lli i = 0; i < a2.size(); i++) //orig
    {
        if (f.find(a2[i]) != f.end()) //common found
            temp.push_back(f[a2[i]]);
    }

    vector<lli> tt;

    if(temp.size() == 0)
        return 0;
    else
    {
        tt.push_back(temp[0]);

        for(lli i = 1; i < temp.size(); i++)
        {
            if (temp[i] > tt[tt.size()-1])
                tt.push_back(temp[i]);

            else if (temp[i] < tt[0])
                tt[0] = temp[i];
            else
            {
                auto ptr = lower_bound(tt.begin(),tt.end(),temp[i]);
                if(ptr != temp.end())
                    *ptr = temp[i];
            }
        }
        return (lli)(tt.size());
    }
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);
        vector<lli> b(n);
        for(lli i=0; i<n; i++)
            cin>>a[i];
        for(lli i=0; i<n; i++)
            cin>>b[i];
        cout<<max_len(b,a)<<"\n";
        t--;
    }
    return 0;
}

