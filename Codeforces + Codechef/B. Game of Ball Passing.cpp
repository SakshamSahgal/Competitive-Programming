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
        lli a[n];
        multiset<lli,greater<lli>> x;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != 0)
                x.insert(a[i]);
        }

        if(x.size() == 0)
            cout<<0<<"\n";
        else if(x.size() == 1)
        {
            lli rem = *x.begin();
            cout<<rem<<"\n";
        }
        else
        {
            auto ptr = x.begin();
            lli maxx = (*ptr);
            ptr++;
            lli sec_max = *ptr;

            x.erase(x.find(maxx));
            x.erase(x.find(sec_max));

            lli me;

            if(maxx == sec_max)
                me = 1;
            else
                me = maxx - sec_max;


            while(x.size() >= 2)
            {
                auto pp = x.begin();
                lli maxx = (*pp);
                x.erase(x.find(maxx));
                if(abs(maxx-me) == 0)
                    me = 1;
                else
                    me = abs(maxx-me);
            }

            lli rem = abs(me - (*x.begin()));
            if(rem != 0)
            cout<<rem<<"\n";
            else
                cout<<1<<"\n";
        }
        t--;
    }
    return 0;
}

