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
        lli n;
        cin>>n;
        vector<lli> a(n);
        vector<lli> b(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        if(a == b)
            cout<<0<<"\n";
        else
        {
            lli c=0;

            lli nozo=0;
            lli nooz=0;
            for(int i=0; i<n; i++)
            {
                if(a[i] == 0 && b[i] == 1)
                    nozo++;
                else if(a[i] == 1 && b[i] == 0)
                    nooz++;
            }

            if(nozo == 0 || nooz == 0)
                cout<<max(nozo,nooz)<<"\n";
            else
            {
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                if(a == b)
                    cout<<1<<"\n";
                else
                {
                    for(int i=0; i<n; i++)
                    {
                        if(a[i] != b[i])
                            c++;
                    }
                    cout<<(1+c)<<"\n";

                }

            }



        }
        t--;
    }
    return 0;
}

