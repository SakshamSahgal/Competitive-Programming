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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<string> x(n);
    vector<pair<lli,lli>> v;
    vector<vector<lli>> pref_2_r(n,vector<lli>(n));
    vector<vector<lli>> pref_2_c(n,vector<lli>(n));

    for(int i=0; i<n; i++)
        cin>>x[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(x[i][j] == '1')
                v.push_back({i,j});
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
                if(x[i][j] == '2' && x[i][j-1] == '2')
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
                if( x[i][j] == '2' && x[i-1][j] == '2')
                    pref_2_c[i][j] = pref_2_c[i-1][j];
                else
                    pref_2_c[i][j] = pref_2_c[i-1][j] + 1;
            }
        }
    }

    if(v.size() == 4)
    {
        if(v[0].first == v[1].first && v[2].first == v[3].first && v[0].second == v[2].second && v[1].second == v[3].second)
        {
            if(v[0].first + 2 <= v[2].first && v[0].second + 2 <= v[1].second)
            {
                if( pref_2_c[v[0].first+1][v[0].second] != pref_2_c[v[2].first-1][v[2].second]  || pref_2_c[v[1].first+1][v[1].second] != pref_2_c[v[3].first-1][v[3].second] || pref_2_r[v[0].first][v[0].second+1] != pref_2_r[v[1].first][v[1].second-1] || pref_2_r[v[2].first][v[2].second+1] != pref_2_r[v[3].first][v[3].second-1])
                    cout<<"No\n";
                else
                {
                    lli i1 = v[0].first+1;
                    lli j1 = v[0].second+1;
                    lli i2 = v[3].first-1;
                    lli j2 = v[3].second-1;

                    bool all_4=1;

                    for(int i=i1;i<=i2;i++)
                    {
                        for(int j=j1;j<=j2;j++)
                        {
                            if(x[i][j] != '4')
                            {
                                all_4 = 0;
                                goto l;
                            }
                        }
                    }

                    l:
                        if(all_4 == 0)
                            cout<<"No\n";
                        else
                        {
                            bool all_zero=1;
                            for(int i=0;i<n;i++)
                            {
                                for(int j=0;j<n;j++)
                                {
                                    if( !(i >= v[0].first && i <= v[2].first && j >= v[0].second && j <= v[1].second) )
                                    {
                                        if(x[i][j] != '0')
                                        {
                                            all_zero = 0;
                                            goto k;
                                        }
                                    }
                                }
                            }
                            k:
                                if(all_zero == 0)
                                    cout<<"No\n";
                                else
                                    cout<<"Yes\n";
                        }
                }
            }
            else
                cout<<"No\n";

        }
        else
            cout<<"No\n";
    }
    else
        cout<<"No\n";

    return 0;
}
