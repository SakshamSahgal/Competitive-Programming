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
        int n,m;
        cin>>n>>m;

        int a[(n*m)];
        lli sum=0;
        for(int i=0; i<n*m; i++)
        {
            cin>>a[i];
            for(int j=i-1; j>=0; j--)
            {
                if(a[j] < a[i])
                    sum++;
            }

        }
        cout<<sum<<"\n";

        t--;
    }
    return 0;
}
