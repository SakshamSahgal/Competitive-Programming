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

lli toi(char x)
{
    return (x - '0');
}

lli all_same(lli x1,lli x2,lli x3,lli x4)
{
    lli d = x1+x2+x3+x4;
    if(d == 2)
        return 2;
    else if(d == 1 || d == 3)
        return 1;
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
        lli n;
        cin>>n;
        vector<string> x(n);
        for(int i=0; i<n; i++)
            cin>>x[i];
        lli c=0;

        if(n%2)
        {

            for(int i=0; i<n/2; i++)
            {
                for(int j=0; j<n/2; j++)
                {
                    lli x1 = toi(x[i][j]);
                    lli x2 = toi(x[j][n-i-1]);
                    lli x3 = toi(x[n-i-1][n-j-1]);
                    lli x4 = toi(x[n-j-1][i]);

                    c += min(x1+x2+x3+x4,n-(x1+x2+x3+x4));
                }
            }

            for(int i=0; i<n/2; i++)
            {
                lli z = toi(x[n/2][i]) + toi(x[n/2][n-i-1]) + toi(x[n-i-1][n/2]) + toi(x[i][n/2]);
                if(z == 2)
                    c += 2;
                else if(z == 1 || z == 3)
                    c += 1;
            }
        }
        else
        {
            for(int i=0; i<n/2; i++)
            {
                for(int j=0; j<n/2; j++)
                {
                    lli x1 = toi(x[i][j]);
                    lli x2 = toi(x[j][n-i-1]);
                    lli x3 = toi(x[n-i-1][n-j-1]);
                    lli x4 = toi(x[n-j-1][i]);

                    c += min(x1+x2+x3+x4,n-(x1+x2+x3+x4));
                }
            }
        }


        cout<<c<<"\n";
        t--;
    }
    return 0;
}
