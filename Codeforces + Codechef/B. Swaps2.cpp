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


void array_printer(lli a[],lli n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);
        vector<lli> b(n);
        lli ans[2*n + 1];
        memset(ans, -1, sizeof(ans));
        for(int i=0;i<n;i++)
         cin>>a[i];
        for(int i=0;i<n;i++)
         cin>>b[i];

        for(int i=0;i<n;i++)
        {
            for(int j=b[i]-1;j>=1;j-=2)
            {
                if(ans[j] == -1)
                    ans[j] = i;
                else
                    break;
            }
        }

        //array_printer(ans,2*n+1);

        lli mini = INT_MAX;

        for(int i=0;i<n;i++)
            mini = min(i + ans[a[i]] , mini);
        cout<<mini<<"\n";

        t--;
    }
    return 0;
}
