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
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        lli uppar=0;
        lli neeche=0;

        for(int i=0; i<n; i++)
        {
            if(b[i] > a[0])
            {
                uppar = i;
                break;
            }
        }

        for(int i=0; i<n; i++)
        {
            if( a[i] < b[0])
            {
               neeche = i;
               break;
            }
        }
        cout<<min(uppar,neeche)<<"\n";
        t--;
    }
    return 0;
}
