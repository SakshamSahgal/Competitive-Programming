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


void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i:x)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<"\n----------------------\n";
}



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    vector<lli> f(1e5+1,0);
    map<lli,lli> z;
    lli ans=1;
    for(int i=0; i<n; i++) //O(n)
    {
        cin>>a[i];
        lli old_freq = f[a[i]];
        if(old_freq != 0)
        {
            z[old_freq]--;
            if(z[old_freq] == 0)
                z.erase(z.find(old_freq));
        }
        f[a[i]]++;
        z[f[a[i]]]++;
        //Map_printer(z);
        if(z.size() == 1 || z.size() == 2)
        {
            vector<lli> ff;
            for(auto i:z)
                ff.push_back(i.first);

            if(z.size() == 1 && ff[0] == 1)
                ans = i+1;
            else if(z.size() == 1 && z[ff[0]] == 1)
                ans = i+1;
            else if(z.size() == 2)
            {
                if(ff[0] == 1 && z[ff[0]] == 1)
                    ans = i+1;
                else if(ff[0]+1 == ff[1] && z[ff[1]] == 1)
                    ans = i+1;
            }
        }

    }
    cout<<ans<<"\n";

    return 0;
}

