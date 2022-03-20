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



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> v(n);
        bool allzero=1;
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            if(v[i] != 0)
                allzero = 0;
        }

        if(allzero)
            cout<<0<<"\n";
        else
        {
            sort(v.begin(),v.end());
            lli pr = v[n-1] - 1;

            for(lli i=n-2; i>=0; i--)
            {
                if(v[i] == pr)
                    pr = 0;
                else if( pr > v[i])
                    pr = pr - v[i];
                else
                    pr = 0;
            }
            if(pr <= 0)
                cout<<1<<"\n";
            else
                cout<<pr+1<<"\n";
        }
        t--;
    }
    return 0;
}

