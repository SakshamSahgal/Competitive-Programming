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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli c[n];
        bool found = 0;
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
            if(c[i] == n)
                found = 1;
        }

        if(found)
        {
            bool fail=0;
            for(int i=0; i<n-1; i++)
            {
                if(c[i] == n)
                {
                    if(c[i+1] != 1)
                    {
                        fail = 1;
                        break;
                    }
                }
                else
                {
                    if(c[i] == 1 && c[i+1] != 2)
                    {
                        fail = 1;
                        break;
                    }
                    else if( c[i] + 1 != c[i+1] )
                    {
                        fail = 1;
                        break;
                    }
                }
            }

            if(fail)
                cout<<"NO\n";
            else
                cout<<"YES\n";

        }
        else
        {
            bool fail=0;
            for(int i=0; i<n-1; i++)
            {
                if(c[i] == 1 && c[i+1] != 2)
                {
                    fail = 1;
                    break;
                }
                else if(c[i+1] > c[i] + 1)
                {
                    fail = 1;
                    break;
                }
            }

            if(fail)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }

        t--;
    }
    return 0;
}

