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
        lli a[n-1];
        for(int i=0;i<n-1;i++)
            cin>>a[i];

        set<lli> rem;
        set<lli> unexpected;

        for(lli i=1;i<=n;i++)
            rem.insert(i);

        for(lli i=0;i<n-1;i++)
        {
            if(i != 0)
            {
                lli th = abs(a[i] - a[i-1]);
                if(rem.count(th)) //if this was expected
                    rem.erase(th);
                else
                    unexpected.insert(th);
            }
            else
            {
                lli th = a[i];
                if(rem.count(th)) //if this was expected
                    rem.erase(th);
                else
                    unexpected.insert(th);
            }
        }

        if(rem.size() == 2 && unexpected.size() == 1)
        {
            lli une = *unexpected.begin();
            auto ptr = rem.begin();
            lli rem1 = *ptr;
            ptr++;
            lli rem2 = *ptr;
            if(rem1 + rem2 == une)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(rem.size() == 1 && unexpected.size() == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";

        t--;
    }
    return 0;
}

