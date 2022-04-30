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

lli max_even(string &s)
{
    lli n = s.length();
    lli c=0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '0')
            c++;
        else
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i] == '1')
                {
                    c++;
                    i=j;
                    break;
                }
            }
        }
    }
    return c;
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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli noo=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
                noo++;
        }

        if(noo%2 == 1 && k%2 == 0)
            cout<<"NO\n";
        else
        {
            if(noo%2 == 0)
            {
                if(k%2 == 0)
                {
                    lli mxe = max_even(s);
                    lli mxo = noo;
                    //cout<<" mxe = "<<mxe<<" "<<"mxo = "<<mxo<<"\n";
                    if( mxe >= k || mxo >= k )
                        cout<<"YES\n";
                    else
                        cout<<"NO\n";
                }
                else
                {
                    lli mxe = max_even(s);
                    if(mxe >= k)
                        cout<<"YES\n";
                    else
                        cout<<"NO\n";
                }
            }
            else
            {
                lli mxo = noo;
                if(mxo >= k)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
        t--;
    }
    return 0;
}
