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

bool all_four(vector<vector<lli>> &pref_4,lli i1,lli j1,lli i2,lli j2)
{
    for(int i=i1; i<=i2; i++)
    {
        if(pref_4[i][j1] != pref_4[i][j2])
            return 0;
    }
    return 1;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<string> v(n);
    vector<vector<lli>> pref_4(n,vector<lli>(n));
    vector<vector<lli>> pref_2_r(n,vector<lli>(n));
    vector<vector<lli>> pref_2_c(n,vector<lli>(n));
    vector<pair<lli,lli>> one_p;
    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j] == '1')
                one_p.push_back({i,j});

            if(j == 0)
                pref_4[i][j] = 1;
            else
            {
                if(v[i][j] == '4' && v[i][j-1] == '4')
                    pref_4[i][j] = pref_4[i][j-1];
                else
                    pref_4[i][j] = pref_4[i][j-1] + 1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == 0)
                pref_2_r[i][j] = 1;
            else
            {
                if(v[i][j] == '2' && v[i][j-1] == '2')
                    pref_2_r[i][j] = pref_2_r[i][j-1];
                else
                    pref_2_r[i][j] = pref_2_r[i][j-1] + 1;
            }
        }
    }

    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(i == 0)
                pref_2_c[i][j] = 1;
            else
            {
                if( v[i][j] == '2' && v[i-1][j] == '2')
                    pref_2_c[i][j] = pref_2_c[i-1][j];
                else
                    pref_2_c[i][j] = pref_2_c[i-1][j] + 1;
            }
        }
    }


    Vec_2d_printer(pref_4);
    Vec_2d_printer(pref_2_r);
    Vec_2d_printer(pref_2_c);




    return 0;
}
