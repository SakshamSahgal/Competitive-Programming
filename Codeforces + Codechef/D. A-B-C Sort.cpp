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
        lli x[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            x[i] = a[i];
        }
        sort(x,x+n);

        lli len = n;

        for(int i=0,j=0; i<n; i++,j++)
        {
            if(len%2 == 1)
            {
                if(x[j] == a[i])
                    len--;
                else
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
            else
            {
                if(i+1 < n)
                {
                    if(x[j] == a[i] && x[j+1] == a[i+1])
                    {
                        j++;
                        i++;
                        len-=2;
                    }
                    else if(x[j+1] == a[i] && x[j] == a[i+1])
                    {
                        j++;
                        i++;
                        len-=2;
                    }
                    else
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }
            }
        }
        cout<<"YES\n";
l:
        t--;
    }
    return 0;
}
