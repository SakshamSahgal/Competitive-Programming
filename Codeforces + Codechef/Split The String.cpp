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

bool check(lli k,lli noo,lli noz,lli mid)
{
    lli c=0;
    if(abs(noo-noz)/mid <= k)
        return 1;
    else
        return 0;
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli noo=0;
        lli noz=0;
        for(lli i=0; i<s.length(); i++)
        {
            if(s[i] == '1')
                noo++;
            else
                noz++;
        }

        if(k == 1)
            cout<<abs(noz-noo)<<"\n";
        else
        {
            if(abs(noo-noz)%k == 0)
                cout<<abs(noz-noo)/k<<"\n";
            else
                cout<<abs(noz-noo)/k+1<<"\n";
        }
        t--;
    }
    return 0;
}

