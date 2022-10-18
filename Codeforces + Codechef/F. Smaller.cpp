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
        lli noas=1;
        lli noat=1;
        bool yes=0;
        bool of=0;
        lli q;
        cin>>q;
        while(q--)
        {
            lli d,k;
            string s;
            cin>>d>>k>>s;
            lli ac=0;
            for(int i=0;i<s.length();i++)
            {
                if(d == 1)
                {
                    if(s[i] == 'a')
                        ac++;
                    else
                        of=1;
                }
                else
                {
                    if(s[i] == 'a')
                        ac++;
                    else if(s[i] > 'a')
                        yes=1;
                }
            }

            if(yes)
                cout<<"YES\n";
            else
            {
                if(d == 1)
                    noas += k*ac;
                else
                    noat += k*ac;

                if(noas < noat && of == 0)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }

        }

        t--;
    }
    return 0;
}
