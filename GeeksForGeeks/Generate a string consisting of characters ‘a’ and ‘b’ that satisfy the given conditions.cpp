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

    int a,b;
    cin>>a>>b;
    string s="";
    while(a != 0 || b != 0)
    {
        if(s.length() >= 2)
        {
            int i=s.length();
            if(a >= b)
            {
                if(s[i-1] == 'a' && s[i-2] == 'a')
                {
                    if(b > 0)
                    {
                        s += 'b';
                        b--;
                    }
                }
                else
                {
                    if(a > 0)
                    {
                        s += 'a';
                        a--;
                    }
                }
            }
            else
            {
                if(s[i-1] == 'b' && s[i-2] == 'b')
                {
                    if(a > 0)
                    {
                        s += 'a';
                        a--;
                    }
                }
                else
                {
                    if(b > 0)
                    {
                        s += 'b';
                        b--;
                    }
                }
            }
        }
        else
        {
            if(a >= b)
            {
                s+='a';
                a--;
            }
            else
            {
                s += 'b';
                b--;
            }
        }
    }
    cout<<s<<"\n";
    return 0;
}
