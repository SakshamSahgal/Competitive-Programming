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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length() == 2)
    {
        if(s[0] == s[1])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    else
    {
        if(s[0] != s[n-1])
        {
            if(s[0] == 'A')
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
        else
        {
            string rem = "";
            for(int i=0; i<n/2; i++)
            {
                if(s[i] != s[n-i-1])
                {
                    lli len = n-2*i;
                    rem = s.substr(i,len);
                    break;
                }
            }

            if(rem.length() == 0)
                cout<<"Yes\n";
            else
            {
                if(s[0] == 'A')
                    cout<<"Yes\n";
                else
                {
                    if(rem.length() == 2)
                        cout<<"No\n";
                    else
                        cout<<"Yes\n";
                }
            }
        }
    }

    return 0;
}
