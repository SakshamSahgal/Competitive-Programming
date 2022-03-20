#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<deque>
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

        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);

        deque<lli> x;

        for(int i=0; i<n; i++)
            x.push_back(a[i]);

        lli sr=0;
        lli sb=0;
        lli cr=0;
        lli cb=0;


        if(x.size() >= 3)
        {
            sr += x.back();
            x.pop_back();
            cr++;
            sb += x.front();
            x.pop_front();
            sb += x.front();
            x.pop_front();
            cb += 2;
        }
        else
        {
            cout<<"NO\n";
            goto l;
        }


        if(cr < cb && sr > sb)
        {
            cout<<"YES\n";
            goto l;
        }
        else
        {
            while(x.size() != 0)
            {
                if(x.size() >= 2)
                {
                    sr += x.back();
                    x.pop_back();
                    cr++;
                    sb += x.front();
                    x.pop_front();
                    cb++;
                }
                else
                {
                    cout<<"NO\n";
                    goto l;
                }

                if(cr < cb && sr > sb)
                {
                    cout<<"YES\n";
                    goto l;
                }
            }
        }

        cout<<"NO\n";
l:
        t--;
    }
    return 0;
}

