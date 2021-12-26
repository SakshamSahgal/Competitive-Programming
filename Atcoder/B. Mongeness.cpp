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
using namespace std;

int main()
{
    //GO_FAST
    lli n,m;
    cin>>n>>m;
    lli a[n][m];
    for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];

    for(int i1=0;i1<n;i1++)
        {
            for(int j1=0;j1<m;j1++)
                {
                   for(int i2=0;i2<n;i2++)
                   {
                       for(int j2=0;j2<m;j2++)
                       {
                           if( ( i1 < i2 && j1 < j2) )
                           {
                                if(a[i1][j1] +  a[i2][j2] > a[i2][j1] + a[i1][j2])
                                {
                                    cout<<"No\n";
                                    //cout<<"for = "<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
                                    //cout<<a[i1][j1]<<"+"<<a[i2][j2]<<" > "<<a[i2][j1]<<"+"<<a[i1][j2]<<"\n";
                                    goto k;
                                }

                           }

                       }
                   }
                }
        }
    cout<<"Yes\n";
    k:
    return 0;
}
