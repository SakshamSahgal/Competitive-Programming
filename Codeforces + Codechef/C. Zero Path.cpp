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
        lli n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        map<lli,lli> f;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
                f[a[i][j]]++;
            }
        }


        if( (n+m-1)%2 == 1)
            cout<<"NO\n";
        else
        {
            lli z = (n+m-1);
            if(f[1] < z/2 || f[-1] < z/2)
                cout<<"NO\n";
            else
            {
                map<pair<int,int>,set<int>> d;

                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(d[ {i,j-1}].size() == 0 && d[ {i-1,j}].size() == 0)
                            d[ {i,j}].insert(a[i][j]);
                        else
                        {
                            for(auto k:d[ {i,j-1}])
                                {
                                    d[ {i,j}].insert(a[i][j] + k);
                                    d[{i,j-2}].clear();
                                }

                            for(auto k:d[ {i-1,j}])
                                {
                                    d[ {i,j}].insert(a[i][j] + k);
                                    d[{i-2,j}].clear();
                                }

                        }
                    }


                }
//
//                for(int i=0;i<n;i++)
//                {
//                    for(int j=0;j<m;j++)
//                    {
//                        cout<<" [ ";
//                        for(auto k:d[{i,j}])
//                                cout<<k<<" ";
//                        cout<<" ] ";
//                    }
//                }

                for(auto j:d[ {n-1,m-1}])
                {
                    if(j == 0)
                    {
                        cout<<"YES\n";
                        goto l;
                    }
                }
                cout<<"NO\n";
            }
        }
l:
        t--;
    }
    return 0;
}
