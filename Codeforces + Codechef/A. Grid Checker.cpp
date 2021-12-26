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
    int t;
    cin>>t;
    while(t)
    {
        char x[3][3];

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            cin>>x[i][j];

        for(int i=0; i<3; i++)
        {
            if( (x[i][0] == x[i][1] && x[i][1] == x[i][2]) || ( x[0][i] == x[1][i] && x[1][i] == x[2][i] ) )
            {
                cout<<"YES\n";
                goto k;
            }
        }

        if ( (x[0][0] == x[1][1] && x[1][1] == x[2][2]) || (x[0][2] == x[1][1] && x[1][1] == x[2][0]) )
        {
            cout<<"YES\n";
            goto k;
        }

        cout<<"NO\n";

k:
        t--;
    }
    return 0;
}
