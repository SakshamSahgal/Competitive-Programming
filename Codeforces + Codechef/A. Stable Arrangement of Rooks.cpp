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
        lli n,k;
        cin>>n>>k;
        if(k > ceil(n/2.0) )
            cout<<"-1\n";
        else
        {
            char a[n][n];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    a[i][j] = '.';
            for(int i=0,j=0; i<k;i++,j+=2)
                a[j][j] = 'R';

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    cout<<a[i][j];

                cout<<"\n";
            }

        }

        t--;
    }
    return 0;
}
