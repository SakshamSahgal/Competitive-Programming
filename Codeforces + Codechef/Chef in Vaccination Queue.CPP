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
        lli n,p,x,y;
        cin>>n>>p>>x>>y;
        int a[n];
        lli sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i+1<=p)
            {
                if(a[i] == 0)
                    sum += x;
                else
                    sum += y;
            }
        }
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}
