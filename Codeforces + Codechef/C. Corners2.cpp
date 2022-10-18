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

bool poss(lli i,lli j,lli n,lli m)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
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
        lli n,m;
        cin>>n>>m;
        vector<string> v(n);
        lli noo=0;
        for(int i=0; i<n; i++)
            cin>>v[i];

        bool zero_f=0;
        bool pass=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j] == '1')
                    noo++;
                else
                {
                    zero_f = 1;

                    for(int k=-1;k<=1;k++)
                    {
                        for(int l=-1;l<=1;l++)
                        {
                            lli ii = i+k;
                            lli jj = j+l;
                            if(!(k == 0 && l == 0) && poss(ii,jj,n,m) && v[ii][jj] == '0')
                                pass = 1;
                        }
                    }
                }
            }
        }

        if(pass)
            cout<<noo<<"\n";
        else
        {
            if(zero_f)
                cout<<noo-1<<"\n";
            else
                cout<<noo-2<<"\n";
        }
        t--;
    }
    return 0;
}

