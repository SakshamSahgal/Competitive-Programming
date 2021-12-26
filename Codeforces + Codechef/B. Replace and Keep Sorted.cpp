#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


lli sum_between(int l,int r,lli prefix[],int n)
{
    if(r<l)
        return 0;
    else if(l == r)
    {
        if(l>1)
            return (prefix[l] - prefix[l-1]);
        else
            return (prefix[l]);
    }
    else
    {
        if(l>1)
            return (prefix[r] - prefix[l-1]);
        else
            return (prefix[r]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,k;
    cin>>n>>q>>k;
    int a[n+1];
     lli sum=0;
    int dp[3][n+1];
    lli prefix_sum[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    dp[2][1] = 0;
    dp[2][n] = 0;

    for(int i=1; i<=n; i++)
    {
        if(i<n)
            dp[0][i] = a[i+1] - 2;
        else
            dp[0][i] = k-1;

        if(i>1)
            dp[1][i] = max(0,k - a[i-1] - 1);
        else
            dp[1][1] = k-1;

        if(i!= 1 && i!=n)
            dp[2][i] = a[i+1] - a[i-1] - 2;

        sum+=dp[2][i];
        prefix_sum[i] = sum;
    }

    while(q--)
    {

        int l,r;
        cin>>l>>r;
        if(l == r)
            cout<<k-1<<"\n";
        else
        {

            /*
            cout<<"\n------------------------\n";
            for(int i=0; i<3; i++)
            {
                for(int j=1; j<=n; j++)
                    cout<<dp[i][j]<<" ";
                cout<<"\n";
            }

            cout<<"\nPrefix sum = \n";
            for(int i=1; i<=n; i++)
                cout<<prefix_sum[i]<<" ";
            cout<<"\n------------------------\n"; */

            cout<<dp[0][l] + sum_between(l+1,r-1,prefix_sum,n) + dp[1][r]<<"\n";
        }



    }


    return 0;
}

