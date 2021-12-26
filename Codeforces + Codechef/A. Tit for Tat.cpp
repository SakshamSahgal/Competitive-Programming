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
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
                cin>>a[i];


        for(int i=0;i<n-1;i++)
            {
                if( k >= a[i])
                {
                    k -= a[i];
                    a[n-1] += a[i];
                    a[i] = 0;
                }
                else
                {
                    a[n-1] += k;
                    a[i] -= k;
                    break;
                }
            }

        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}


