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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n<250)
        {
            lli maxx = INT_MIN;
            for(lli i=0; i<n; i++)
            {
                for(lli j=i+1; j<n; j++)
                {
                    if( maxx < ((i+1)*(j+1) - k*(a[i]|a[j])) )
                        maxx = ((i+1)*(j+1) - k*(a[i]|a[j]));
                }
            }
            cout<<maxx<<"\n";
        }
        else
        {
            lli maxx = INT_MIN;
            for(lli i=n-202; i<n; i++)
            {
                for(lli j=n-202; j<n; j++)
                {
                    if(i != j)
                    {
                        if( maxx < ((i+1)*(j+1) - k*(a[i]|a[j])) )
                            maxx = ((i+1)*(j+1) - k*(a[i]|a[j]));
                    }

                }
            }
            cout<<maxx<<"\n";
        }

        t--;
    }


    return 0;
}

