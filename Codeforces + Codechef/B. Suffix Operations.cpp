#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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
        lli rep_with[n];
        lli g[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
        {
            lli before = 0;
            lli after = 0;
            lli rw;
            if(i == 0)
            {
                before = abs(a[i] - a[i+1]);
                after = 0;
                rw = a[i+1];
            }
            else if(i == n-1)
            {
                before = abs(a[i-1] - a[i]);
                after = 0;
                rw = a[i-1];
            }
            else
            {
                before = abs(a[i-1] - a[i]) + abs( a[i+1] - a[i]);
                lli x = a[i];
                x = max(a[i-1],a[i+1]);
                rw = x;
                after = abs(a[i-1] - x) + abs(a[i+1] - x);
            }

            //cout<<"i = "<<i<<" before = "<<before<<" after = "<<after<<" gain = "<<before - after<<" replace "<<a[i]<<" with "<<rw<<"\n";
            g[i] = (before - after);
            rep_with[i] = rw;
        }

        lli maxx_gain = INT_MIN;
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(g[i] > maxx_gain)
            {
                maxx_gain = g[i];
                index = i;
            }
        }

        a[index] = rep_with[index];

        lli sum=0;

        for(int i=n-1;i>0;i--)
                sum+= abs(a[i]-a[i-1]);
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}


