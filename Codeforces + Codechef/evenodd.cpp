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

lli moves_req(lli z)
{
    lli c=0;
    while(z%2 == 0)
    {
        z/=2;
        c++;
    }
    return c;
}

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
        lli a[2*n];
        vector<lli> em;
        lli e=0;
        lli o=0;
        for(int i=0; i<2*n; i++)
        {
            cin>>a[i];

            if(a[i]%2 == 0)
            {
                e++;
                em.push_back(moves_req(a[i]));
            }
            else
                o++;
        }

        if(e == o)
            cout<<0<<"\n";
        else if( o > e)
            cout<<(o - n)<<"\n";
        else
        {
            sort(em.begin(),em.end());
            lli req = e - n;
            lli s=0;
            for(int i=0; i<req; i++)
                s += em[i];
            cout<<s<<"\n";
        }
        t--;
    }
    return 0;
}
