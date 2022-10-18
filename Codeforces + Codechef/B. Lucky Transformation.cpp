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

    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0; i<n-1; i++)
    {
        if(k == 0)
            break;
        if(s[i] == '4' && s[i+1] == '7')
        {
            if( (i+1)%2 == 0 && i-1 >= 0 && s[i-1] == '4' )
            {
                if(k%2)
                {
                    s[i-1] = '4';
                    s[i] = '7';
                    s[i+1] = '7';
                }
                break;
            }
            else if( (i+1)%2 == 1 && i+2 < n && s[i+2] == '7')
            {
                if(k%2)
                {
                    s[i] = '4';
                    s[i+1] = '4';
                    s[i+2] = '7';
                }
                break;
            }
            else
            {
                if((i+1)%2)
                {
                    s[i] = '4';
                    s[i+1] = '4';
                }
                else
                {
                    s[i] = '7';
                    s[i+1] = '7';
                }
                k--;
            }
        }
    }
    cout<<s<<"\n";

    return 0;
}

