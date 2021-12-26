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
    GO_FAST
        int n;
        cin>>n;
        lli a[n+1];

        lli x[n+1][n+1];

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cin>>x[i][j];
        }


        a[1] = sqrt( (x[1][2] * x[1][3] / x[2][3]) );
        for(int i=2; i<=n; i++)
        {
            a[i] = x[1][i]/a[1];
        }
        for(int i=1; i<=n; i++)
            cout<<a[i]<<" ";

        cout<<"\n";

    return 0;
}
