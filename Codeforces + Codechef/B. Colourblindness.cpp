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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;

        for(int i=0;i<n;i++)
        {
            lli r=0;
            lli g=0;
            lli b=0;

            if(s1[i] == 'R')
                r++;
            if(s2[i] == 'R')
                r++;
            if(s1[i] == 'G')
                g++;
            if(s2[i] == 'G')
                g++;
            if(s1[i] == 'B')
                b++;
            if(s2[i] == 'B')
                b++;
            if( (r == 1 && g == 1) || (r == 1 && b == 1) )
            {
                cout<<"NO\n";
                goto l;
            }

        }
        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}

