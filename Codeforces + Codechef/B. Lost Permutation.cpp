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
    int t;
    cin>>t;
    while(t)
    {
        lli m,fs;
        cin>>m>>fs;
        lli a[m];
        set<lli> have;
        for(int i=0; i<m; i++)
        {
            cin>>a[i];
            have.insert(a[i]);
        }

        bool found=0;
        for(lli i=1; i<=1000; i++)
        {
            if(!have.count(i))
            {
                fs -= i;
                have.insert(i);
            }

            if(fs == 0)
            {
                found = 1;
                break;
            }
            else if(fs < 0)
                break;
        }

        if(found)
        {
            vector<lli> z;
            for(auto i:have)
                z.push_back(i);

            for(int i=0; i<z.size(); i++)
            {
                if(z[i] != i+1)
                {
                    found = 0;
                    break;
                }
            }
        }


        if(found)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }
    return 0;
}
