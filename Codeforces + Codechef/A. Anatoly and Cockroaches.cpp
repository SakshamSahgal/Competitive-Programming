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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    string s;
    cin>>s;
    char x = 'r';
    char y = 'r';
    lli rb1=0;
    lli rb2=0;
    lli br1=0;
    lli br2=0;
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            x = 'r';
            y = 'b';
        }
        else
        {
            x = 'b';
            y = 'r';
        }

        if(s[i] == 'r' && x == 'b')
            rb1++;
        if(s[i] == 'b' && x == 'r')
            br1++;
        if(s[i] == 'r' && y == 'b')
            rb2++;
        if(s[i] == 'b' && y == 'r')
            br2++;

    }

    lli a1 = max(rb1,br1);
    lli a2 = max(rb2,br2);

    cout<<min(a1,a2)<<"\n";

    return 0;
}

