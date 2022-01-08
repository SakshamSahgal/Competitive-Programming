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
    lli n;
    cin>>n;
    lli R[n+1];
    lli C[n+1];

    for(int i=1; i<=n; i++)
        cin>>R[i];

    for(int i=1; i<=n; i++)
        cin>>C[i];

    lli ans[n];



    lli q;
    cin>>q;

    while(q--)
    {
        lli r,c;
        cin>>r>>c;

        lli maxx = n/2 + 1; //n to n/2 + 1
        lli mini = n/2;  // 1 to n/2

        if( ( max(R[r],C[c]) >= n/2 + 1 && max(R[r],C[c]) <= n ) && ( min(R[r],C[c]) >= 1 && min(R[r],C[c]) <= n/2 ) )
        {
            lli max_index = 2*(n + 1 - max(R[r],C[c])) - 1;
            lli min_index = 2*min(R[r],C[c]);
            if(max_index < min_index)
                cout<<"#";
            else
                cout<<".";
        }
        else if( ( max(R[r],C[c]) >= n/2 + 1 && max(R[r],C[c]) <= n ) && !( min(R[r],C[c]) >= 1 && min(R[r],C[c]) <= n/2 ) )
          cout<<"#";
        else
            cout<<".";
    }

    return 0;
}
