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
    //GO_FAST

        lli n,l,k;
        cin>>n>>l>>k;
        vector<lli> x(n+1);
        vector<lli> a(n);
        x[n] = l;
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
            cin>>a[i];

        dp[k+1][n+1];

        for(int i=0;i<k+1;i++)
            for(int j=0;j<n+1;j++)
                dp[i][j] = 0;


        for(int i=0;i<n;i++)
        {


        }
    return 0;
}
