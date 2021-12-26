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
void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}
int main()
{
    GO_FAST
    lli n,m;
    cin>>n>>m;
    char a[n][m];
    set<lli> badmash;
    for(lli i=0; i<n; i++)
    {
        for(lli j=0; j<m; j++)
            cin>>a[i][j];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(a[i-1][j] == 'X' && a[i][j-1] == 'X')
                badmash.insert(j+1);
        }
    }
    //set_printer(badmash);
    lli q;
    cin>>q;

    for(lli i=0; i<q; i++)
    {
        lli x1,x2;
        cin>>x1>>x2;
        if( x2-x1 == 0 )
            cout<<"YES\n";
        else
        {
            auto ptr = badmash.lower_bound(x1);
           // cout<<*ptr<<"\n";
            if( *ptr > x1 && *ptr <= x2 )
                cout<<"NO\n";
            else if( *ptr == x1 )
            {
                if( ptr != badmash.end() )
                {
                    ptr++;
                    if( *ptr > x1 && *ptr <= x2 )
                        cout<<"NO\n";
                    else
                        cout<<"YES\n";
                }
                else
                    cout<<"YES\n";
            }
            else
                cout<<"YES\n";
        }
    }
    return 0;
}
