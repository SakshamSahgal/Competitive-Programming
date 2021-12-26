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
        lli n;
        cin>>n;
        lli a[n];
        lli maxx = INT_MIN;
        lli prod;
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n-1; i++)
        {
            prod = a[i]*a[i+1];
            if(prod > maxx)
                maxx = prod;
        }
        cout<<maxx<<"\n";
        t--;
    }
    return 0;
}

