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
        lli a[n];
        map<lli,lli> f;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        lli c=0;
        for(int i=1; i<n-1; i++)
        {
            if(a[i-1] > a[i] && a[i] < a[i+1])
                c++;
        }

        if(c <= 1)
        {
            bool fail = 0;
            bool one_found = 0;
            for(int i=0; i<n-1; i++)
            {
                if(a[i] == 1)
                    one_found = 1;

                if(!one_found)
                {
                    if(a[i] == n)
                    {
                        if(a[i+1] != 1)
                        {
                            fail = 1;
                            break;
                        }
                    }
                    else
                    {
                        if( a[i]+1 < a[i+1] )
                        {
                            fail = 1;
                            break;
                        }
                    }
                }
                else
                {
                    if(a[i+1] - 1 != a[i])
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
            cout<<"NO\n";


        t--;
    }
    return 0;
}

