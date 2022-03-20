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
        lli n,m,r,c;
        cin>>n>>m>>r>>c;
        char x[n][m];
        bool all_w = 1;
        bool one = 0;
        bool zero = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>x[i][j];
                if(x[i][j] == 'B')
                    all_w = 0;
                if(x[i][j] == 'B' && i+1 == r && j+1 == c)
                    zero = 1;
                if(x[i][j] == 'B' && (i+1 == r || j+1 == c))
                    one = 1;
            }
        }

        if(all_w == 1)
            cout<<-1<<"\n";
        else if(zero == 1)
            cout<<0<<"\n";
        else if(one == 1)
            cout<<1<<"\n";
        else
            cout<<2<<"\n";
        t--;
    }
    return 0;
}
