#include<iostream>
#include<algorithm>
#include <climits>
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
        int n,k;
        cin>>n>>k;
        int a[n+1];
        int b[n+1];
        b[1] = 0;
        b[n] = 0;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=2; i<n; i++)
        {

            if( (a[i] > a[i-1]) && (a[i] > a[i+1]) )
                b[i] = 1;
            else
                b[i] = 0;
        }

        //cout<<"\n";
        for(int i=2; i<=n; i++)
            b[i] = b[i-1] + b[i];

        //for(int i=1; i<=n; i++)
           // cout<<b[i]<<" ";
        //cout<<"\n";
        int l[n-k+2];

        for(int i=1; i<=(n-k+1); i++)
            l[i] = (b[(i+k-2)] - b[i]);

        int maxi = INT_MIN;
        int maxi_index = 1;
        //cout<<"\n";
        for(int i=1; i<=(n-k+1); i++)
        {
            if(l[i] > maxi)
            {
                maxi = l[i];
                maxi_index = i;
            }


            //cout<<l[i]<<" ";
        }
        //cout<<"\n";
        cout<<maxi+1<<" "<<maxi_index<<"\n";
            t--;
    }

    return 0;
}

