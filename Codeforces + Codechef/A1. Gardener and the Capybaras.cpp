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
    set<string> z;
    z.insert("ba");
    z.insert("b");
    for(auto i:z)
        cout<<i<<" ";
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        string aa = "";
        string bb = "";
        lli n = s.length();
        for(int i=0;i<n-2;i++)
        {
            aa += s[i];
            string bb;
            for(int j=i+1;j<n-1;j++)
            {
                bb += s[j];
                lli len = s.length() - j - 1;
                string cc = s.substr(j+1,len);
                //cout<<aa<<" "<<bb<<" "<<cc<<"\n";

                if( ( aa <= bb && cc <= bb) || ( bb <= aa && bb <= cc) )
                {
                    cout<<aa<<" "<<bb<<" "<<cc<<"\n";
                    goto l;
                }
            }
        }
        cout<<":(\n";
        l:
        t--;
    }
    return 0;
}

