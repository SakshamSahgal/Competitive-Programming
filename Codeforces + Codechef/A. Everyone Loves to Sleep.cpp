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
        vector<vector<lli>> time(24,vector<lli>(60,0));
        lli n,h,m;
        cin>>n>>h>>m;

        for(int i=0; i<n; i++)
        {
            lli a,b;
            cin>>a>>b;
            time[a][b] = 1;
        }

        lli c=0;

        for(int j=m; j<60; j++)
        {
            if(time[h][j])
            {
                lli h = c/60;
                lli m = c%60;
                cout<<h<<" "<<m<<"\n";
                goto l;
            }
            c++;
        }

        for(int i=h+1; i<24; i++)
        {
            for(int j=0; j<60; j++)
            {
                if(time[i][j])
                {
                    lli h = c/60;
                    lli m = c%60;
                    cout<<h<<" "<<m<<"\n";
                    goto l;
                }
                c++;
            }
        }

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<60; j++)
            {
                if(time[i][j])
                {
                    lli h = c/60;
                    lli m = c%60;
                    cout<<h<<" "<<m<<"\n";
                    goto l;
                }
                c++;
            }
        }

        for(int j=0; j<m; j++)
        {
            if(time[h][j])
            {
                lli h = c/60;
                lli m = c%60;
                cout<<h<<" "<<m<<"\n";
                goto l;
            }
            c++;
        }


l:

        t--;
    }
    return 0;
}

