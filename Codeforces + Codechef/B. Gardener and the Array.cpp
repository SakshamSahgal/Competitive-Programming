
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
        lli n;
        cin>>n;
        vector<vector<lli>> v(n);
        map<lli,lli> f;
        for(int i=0;i<n;i++)
        {
            lli z,ki;
            cin>>z;
            for(int j=0;j<z;j++)
            {
                cin>>ki;
                v[i].push_back(ki);
                f[ki]++;
            }
        }

        for(int i=0;i<n;i++)
        {
            bool found=0;
            for(int j=0;j<v[i].size();j++)
            {
                if(f[v[i][j]] == 1)
                {
                    found = 1;
                    break;
                }
            }

            if(!found)
            {
                cout<<"Yes\n";
                goto l;
            }
        }
        cout<<"No\n";
        l:
        t--;
    }
    return 0;
}
