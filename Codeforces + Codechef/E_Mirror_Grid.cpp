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
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    int t;
    cin >> t;
    while (t)
    {
        lli n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        lli c = 0;
        
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    lli x1 = (s[i][j] - '0');
                    lli x2 = (s[n - j - 1][i] - '0');
                    lli x3 = (s[n - i - 1][n - j - 1] - '0');
                    lli x4 = (s[j][n - i - 1] - '0');
                    if ((n % 2))
                    {
                        if (!(i == n / 2 && j == n / 2))
                        {
                            lli d = x1 + x2 + x3 + x4;
                            if (d == 1 || d == 3)
                                c += 1;
                            else if (d == 2)
                                c += 2;
                        }
                    }
                    else
                    {
                            lli d = x1 + x2 + x3 + x4;
                            if (d == 1 || d == 3)
                                c += 1;
                            else if (d == 2)
                                c += 2;
                    }
                }
            }
            cout<<c/4<<"\n";
            t--;
    }
    return 0;
}