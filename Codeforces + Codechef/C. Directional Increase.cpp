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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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
        lli a[n];
        vector<lli> ps(n,0);
        lli s=0;
        bool allz = 1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != 0)
                allz = 0;
            s += a[i];
            ps[i] = (i == 0) ? a[i] : a[i] + ps[i-1];
        }
        if(allz == 1)
            cout<<"Yes\n";
        else
        {
            if(s != 0)
                cout<<"No\n";
            else
            {
                //vector_printer(ps);
                lli fz=n-1;

                for(int i=n-1; i>=0; i--)
                {
                    if(ps[i] != 0)
                    {
                        fz = i+1;
                        break;
                    }
                }
                //cout<<fz<<"\n";
                for(int i=0; i<fz; i++)
                {
                    if(ps[i] <= 0)
                    {
                        cout<<"No\n";
                        goto l;
                    }
                }
                cout<<"Yes\n";
            }


        }


l:
        t--;
    }
    return 0;
}
