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
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        lli a[n];
        lli sum=0;
        lli tot_sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tot_sum+=a[i];
        }

        sort(a,a+n);
        double maxx = INT_MIN;
        for(int i=0;i<(n-1);i++)
            {
                sum += a[i];
                double a = sum/(i+1.0);
                double b = (tot_sum - sum)/(n-1.0-i);
                maxx = max((a+b),maxx);
            }
        cout<<setprecision(9)<<maxx<<"\n";
        t--;
    }
    return 0;
}

