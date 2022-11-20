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

//remember to use endl instead of \n for interactive problems.




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
        lli a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
        {
            if(a[i]%2)
                a[i] = a[i] + a[i]%10;
        }

        lli c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%10 == 0)
                c++;
        }

        if(c == n || c == 0)
        {
            if(c == n)
            {
                bool fail=0;
                lli z = a[0];
                for(int i=1;i<n;i++)
                {
                    if(a[i] != z)
                    {
                        fail = 1;
                        break;
                    }
                }

                if(fail)
                    cout<<"No\n";
                else
                    cout<<"Yes\n";
            }
            else
            {
                bool m1=0;
                bool m2=0;
                for(int i=0;i<n;i++)
                {
                    if(a[i]%20 == 2 || a[i]%20 == 4 || a[i]%20 == 8 || a[i]%20 == 16)
                        m1=1;

                    if(a[i]%20 == 12 || a[i]%20 == 14 || a[i]%20 == 18 || a[i]%20 == 6)
                        m2=1;
                }

                if(m1 == 1 && m2 == 1)
                    cout<<"No\n";
                else
                    cout<<"Yes\n";

            }
        }
        else
            cout<<"No\n";

        t--;
    }
    return 0;
}
