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
        string a,b;
        cin>>a>>b;
        lli aa=0,bb=0;
        if(a[0] == 'M')
            aa = 5;
        else
        {
            if(a[a.length()-1] == 'S')
                aa -= 10*(a.length());
            else
                aa += 10*(a.length());
        }

        if(b[0] == 'M')
            bb = 5;
        else
        {
            if(b[b.length()-1] == 'S')
                bb -= 10*(b.length());
            else
                bb += 10*(b.length());
        }

        if(aa == bb)
            cout<<"=\n";
        else if(aa < bb)
            cout<<"<\n";
        else
            cout<<">\n";

        t--;
    }
    return 0;
}
