#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli sum_between(int l,int r,lli sum[],lli n)
{
    if(l == 0)
        return sum[r];
    else
    {
        if(r >= l)
            return (sum[r] - sum[l-1]);
        else
            return 0;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n];
    lli prefix[n];
    lli sum=0;
    double maxx = INT_MIN;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
        prefix[i] = sum;
    }

    for(int i=k; i<=n; i++)
    {
        //cout<<"i = "<<i<<"\n";
        for(int l = 0,r = l+i-1; r<n; l++,r++)
        {
          //cout<<sum_between(l,r,prefix,n)<<"\n";
          double ans = (sum_between(l,r,prefix,n))/(i*1.0);
          if( ans > maxx)
                maxx = ans;
        }

    }
    cout<<(setprecision(16))<<maxx<<"\n";
    return 0;
}

