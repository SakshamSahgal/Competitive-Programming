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
        lli noz=0;
        lli noo=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
                noz++;
            if(a[i] == 1)
                noo++;
        }


        sort(a,a+n);

        if(a[0] == a[n-1])
            cout<<"YES\n";
        else
        {
            if(noz > 0 && noo > 0)
                cout<<"NO\n";
            else if(noz == 0 && noo > 0)
            {
                bool fail=0;
                for(int i=0;i<n;i++)
                {
                    if(a[i] == 2)
                    {
                        fail = 1;
                        break;
                    }
                }

                for(int i=0;i<n-1;i++)
                {
                    if(a[i] + 1 == a[i+1])
                    {
                        fail = 1;
                        break;
                    }
                }

                if(!fail)
                {
                    cout<<"YES\n";
                    goto l;
                }
                else
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
            else
                cout<<"YES\n";
        }
        l:
        t--;
    }
    return 0;
}

