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
        lli tt = floor( log2l(k) + 1 );
        lli maxx = pow(2,tt);
        //cout<<"time = "<<tt<<" maxx computers = "<<maxx<<"\n";
        if(n == 1)
            cout<<0<<"\n";
        else
        {
            if( maxx >= n )
            {
                if(maxx == n)
                    cout<<tt<<"\n";
                else
                {
                    for(lli i=0; i<=tt; i++)
                    {
                        if(  n <= pow(2,i) )
                        {
                            cout<<i<<"\n";
                            break;
                        }
                    }
                }
            }
            else
            {
                if ( (n - maxx)%k == 0 )
                    cout<<(n-maxx)/k + tt<<"\n";
                else
                    cout<<(n-maxx)/k + tt + 1<<"\n";
            }
        }
        t--;
    }
    return 0;
}
