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
        string s;
        cin>>s;

        if(s.length() == 1)
        {
            if(s[0] == 'Y' || s[0] == 'e' || s[0] == 's')
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            bool fail = 0;
            for(int i=0; i<s.length()-1; i++)
            {
                if(s[i] == 'Y' || s[i] == 'e' || s[i] == 's')
                {
                    if(s[i] == 'Y' && s[i+1] != 'e')
                    {
                        fail=1;
                        break;
                    }
                    else if(s[i] == 'e' && s[i+1] != 's')
                    {
                        fail=1;
                        break;
                    }
                    else if(s[i] == 's' && s[i+1] != 'Y')
                    {
                        fail=1;
                        break;
                    }
                }
                else
                {
                    fail=1;
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

