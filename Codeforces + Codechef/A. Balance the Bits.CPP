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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vector<char> s1(n);
        vector<char> s2(n);
        lli noz=0;
        lli noo=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                noz++;
            else
                noo++;
        }
        lli zf=0;
        lli of=0;
        if(noo%2 == 0 && noz%2 == 0 && s[0] == '1' && s[n-1] == '1')
        {
            for(int i=0; i<n; i++)
            {
                if(s[i] == '0')
                {
                    zf++;
                    if(zf%2)
                    {
                        s1[i] = '(';
                        s2[i] = ')';
                    }
                    else
                    {
                        s1[i] = ')';
                        s2[i] = '(';
                    }
                }
                else
                {
                    of++;
                    if(of <= noo/2)
                    {
                        s1[i] = '(';
                        s2[i] = '(';
                    }
                    else
                    {
                        s1[i] = ')';
                        s2[i] = ')';
                    }
                }
            }
            cout<<"YES\n";
            for(auto i:s1)
                cout<<i;
            cout<<"\n";
            for(auto i:s2)
                cout<<i;
            cout<<"\n";
        }
        else
            cout<<"NO\n";

        t--;
    }
    return 0;
}
