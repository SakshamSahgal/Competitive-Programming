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
        lli n,m,k;
        cin>>n>>m>>k;
        if(n == 1)
        {
            if( (k - 2) >= 0 )
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(n == 2)
        {
            if(m == 1)
            {
                if( (k-2) >= 1)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                cout<<"NO\n";
        }
        else
        {
            lli mini_m = n-1; //dia = 2
            lli maxi_m = (n*(n-1))/2; // dia 1

            if(m < mini_m || m > maxi_m)
                cout<<"NO\n";
            else
            {
                if(m == maxi_m)
                {
                    if( (k-2) >= 1 )
                        cout<<"YES\n";
                    else
                        cout<<"NO\n";
                }
                else
                {
                    if( (k-2) >= 2 )
                        cout<<"YES\n";
                    else
                        cout<<"NO\n";
                }
            }
        }
        t--;
    }
    return 0;
}
