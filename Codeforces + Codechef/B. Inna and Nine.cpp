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
    string s;
    cin>>s;
    lli i=0;
    lli j=0;
    lli ans=1;
    while(i < s.length())
    {
        j=i;
        lli len=1;
        while(j + 1 < s.length() && (s[j+1] - '0') + (s[j] - '0') == 9 )
        {
            j++;
            len++;
        }
        //cout<<"st = " <<i<<" ed = "<<j<<" len = "<<len<<"\n";
        if(len%2 == 1 && len != 1)
            ans *= (len/2 + 1);
        i = j+1;
    }
    cout<<ans<<"\n";
    return 0;
}

