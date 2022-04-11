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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    int n;
    cin>>n;
    vector<vector<lli>> mat(n+1,vector<lli>((n+1),0));
    int ii,jj;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 0)
            {
                ii = i;
                jj = j;
            }
            mat[i][n] += mat[i][j];
            mat[n][j] += mat[i][j];
        }
    }

    //Vec_2d_printer(mat);

    if(n == 1)
        cout<<1<<"\n";
    else
    {
        if(mat[ii][n] != mat[n][jj])
            cout<<"-1\n";
        else
        {
            bool fail=0;
            int s1,s2;

            lli iii=0;
            lli jjj=0;

            (ii == 0)?iii=1:iii=0;
            (jj == 0)?jjj=1:jjj=0;

            lli tmr = mat[n][jjj];
            lli tmc = mat[iii][n];

            for(int j=0; j<n; j++)
            {
                if(j != jj && tmr != mat[n][j])
                {
                    fail = 1;
                    break;
                }
            }

            for(int i=0; i<n; i++)
            {
                if(i != ii && tmc != mat[i][n])
                {
                    fail = 1;
                    break;
                }
            }


            if(fail || tmr != tmc)
            {
                cout<<"-1\n";
                return 0;
            }
            else
            {
                if(mat[n][jj] >= tmr)
                    cout<<"-1\n";
                else
                {
                    mat[ii][jj] = (tmr-mat[n][jj]);
                    lli d1=0,d2=0;

                    for(int i=0;i<n;i++)
                        d1 += mat[i][i];

                    for(int i=0;i<n;i++)
                        d2 += mat[i][n-i-1];

                    if(!(d1 == d2 && d2 == tmr))
                        cout<<"-1\n";
                    else
                        cout<<mat[ii][jj]<<"\n";
                }

            }
        }
    }
    return 0;
}
