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
        lli nz=0;
        lli noo=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i] == 0)
                nz++;
            if(a[i] == 1)
                noo++;
        }

        cout<<(lli)(pow(2,nz)*noo)<<"\n";

        t--;
    }
    return 0;
}
