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

//remember to use endl instead of \n for interactive problems.

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        string s;

        for(int i=0;i<m;i++)
            s+='B';
        for(int i=0;i<n;i++)
        {
            lli aa = a[i] - 1;
            lli bb = m - a[i];

            if(aa <= bb)
            {
                if(s[aa] == 'A')
                    s[bb] = 'A';
                else
                    s[aa] = 'A';
            }
            else
            {
                if(s[bb] == 'A')
                    s[aa] = 'A';
                else
                    s[bb] = 'A';
            }

        }
        cout<<s<<"\n";
        t--;
    }
    return 0;
}
