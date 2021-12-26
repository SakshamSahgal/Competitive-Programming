#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        lli k[n];
        lli c[m];
        lli x;
        lli sum=0;
        lli last_purchase=1;
        for(int i=0; i<n; i++)
            cin>>k[i];

        for(int i=0; i<m; i++)
        {
            cin>>c[i];
        }
        sort(k,k+n,greater<int>());
        for(int i=0; i<n; i++)
        {
            if(k[i] > last_purchase )
            {
                sum+=c[last_purchase-1];
                last_purchase++;
            }
            else
                sum+= c[k[i]-1];
        }

        /*for(int i=0;i<n;i++)
            cout<<k[i]<<" ";
        cout<<"\n";*/

        cout<<sum<<"\n";
        t--;
    }

    return 0;
}

