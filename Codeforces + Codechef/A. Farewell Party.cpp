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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    map<lli,vector<lli>> f;
    lli zc = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 0)
            zc++;
        f[a[i]].push_back(i);
    }

    if(zc >= 1 && zc < n)
        cout<<"Impossible\n";
    else
    {
        lli ans[n];
        lli h=1;
        bool poss=1;
        for(auto i:f)
        {
            lli c=0;
            lli z = n - i.first;
            if(i.second.size()%z != 0)
            {
                poss = 0;
                break;
            }
            for(auto j:i.second)
            {
                ans[j] = h;
                z--;
                if(z == 0)
                {
                    h++;
                    z = n - i.first;
                }
            }
        }


        for(auto i:ans)
        {
            if(i > n)
                poss = 0;
        }

        if(poss)
        {
            cout<<"Possible\n";
            for(auto i:ans)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
            cout<<"Impossible\n";

    }


    return 0;
}

