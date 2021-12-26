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
lli LCM(lli a,lli b)
{
    return ((a*b)/__gcd(a,b));
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
        lli a[n],b[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n%2 == 0)
        {
            for(int i=0; i<n; i+=2)
            {
                b[i] = LCM(a[i],a[i+1])/a[i];
                b[i+1] = (-1)*LCM(a[i],a[i+1])/a[i+1];
            }
            for(int i=0; i<n; i++)
                cout<<b[i]<<" ";

        }
        else
        {
            for(int i=0; i<=n-5; i+=2)
            {
                b[i] = LCM(a[i],a[i+1])/a[i];
                b[i+1] = (-1)*LCM(a[i],a[i+1])/a[i+1];
            }

            lli abs_sum=0;

            for(int i=0; i<=n-5; i++)
                abs_sum += abs(b[i]);

            lli s = a[n-1] + a[n-2] + a[n-3];

            for(int i=n-3; i<n; i++)
            {
                lli rem = (s - a[i]);
                lli abss = abs_sum + abs(a[i]*2) + abs(rem);
                if( rem != 0 && abss <= 1000000000 )
                {
                   for(int j=n-3;j<n;j++)
                   {
                       if(i!=j)
                           b[j] = a[i];
                       else
                            b[j] = -rem;
                   }
                    break;
                }
            }

            for(int i=0; i<n; i++)
                cout<<b[i]<<" ";
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
