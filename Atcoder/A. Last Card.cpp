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

        lli n,k,a;
        cin>>n>>k>>a;
        lli i;
        lli j;
        for(i=a,j=1;j<=k;j++)
        {
           // cout<<i<<" < - \n";
            if(j < k)
            {
                if(i == n)
                i = 1;
            else
                i++;
            }

        }

         cout<<i<<"\n";

    return 0;
}
