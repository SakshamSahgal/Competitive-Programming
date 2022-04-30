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
        bool mat[n][n];
        bool all_zero = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j] == 1)
                    all_zero = 0;
            }

        }

        if(all_zero)
            cout<<1<<"\n";
        else
        {
            lli fr=0;
            lli lr=n-1;
            lli fc=0;
            lli lc=n-1;

            for(int i=0; i<n; i++)
            {
                bool passed = 0;
                for(int j=0; j<n; j++)
                {
                    if(mat[i][j] == 1)
                    {
                        fr = i;
                        passed = 1;
                        break;
                    }
                }

                if(passed)
                    break;
            }


            for(int i=n-1; i>=0; i--)
            {
                bool passed = 0;
                for(int j=0; j<n; j++)
                {

                    if(mat[i][j] == 1)
                    {
                        lr = i;
                        passed = 1;
                        break;
                    }
                }

                if(passed)
                    break;
            }



            for(int j=0; j<n; j++)
            {
                bool passed = 0;
                for(int i=0; i<n; i++)
                {
                    if(mat[i][j] == 1)
                    {
                        fc = j;
                        passed = 1;
                        break;
                    }
                }

                if(passed)
                    break;
            }

            for(int j=n-1; j>=0; j--)
            {
                bool passed = 0;
                for(int i=0; i<n; i++)
                {
                    if(mat[i][j] == 1)
                    {
                        lc = j;
                        passed = 1;
                        break;
                    }
                }

                if(passed)
                    break;
            }

            //cout<<fr<<" "<<lr<<" "<<fc<<" "<<lc<<"\n";
            lli c=0;
            for(int i=fr; i<=lr; i++)
            {
                for(int j=fc; j<=lc; j++)
                {
                    if(mat[i][j] == 0)
                        c++;
                }
            }
            cout<<c<<"\n";
        }


        t--;
    }
    return 0;
}
