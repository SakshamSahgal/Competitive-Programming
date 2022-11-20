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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];
    set<lli> z;
    for(lli i=1; i<=n; i++)
        z.insert(i);

    for(lli i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] != 0)
            z.erase(z.find(a[i]));
    }

    deque<lli> zz;

    for(auto i:z)
        zz.push_back(i);

    lli fz=-1;

    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            fz = i;
            break;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(a[i] == 0)
        {
            if(i+1 == zz.front())
            {
                a[i] = zz.back();
                zz.pop_back();
            }
            else
            {
                a[i] = zz.front();
                zz.pop_front();
            }
        }

    }

    for(int i=0;i<n;i++)
    {
        if(a[i] == i+1)
            swap(a[i],a[fz]);
    }

    for(auto i:a)
        cout<<i<<" ";

    return 0;
}