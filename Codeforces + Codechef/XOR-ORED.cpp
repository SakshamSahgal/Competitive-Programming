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

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli x = a[0];

        // cout<<"X = "<<x<<" ";
        int orr = (a[0]^x);
        for(int i=0; i<n; i++)
            orr = (a[i]^x)|orr;

        cout<<x<<" "<<orr<<"\n";
        t--;
    }


return 0;
}

