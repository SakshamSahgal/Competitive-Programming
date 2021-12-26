
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
        int n,d;
        cin>>n>>d;
        int a[n];
        bool gtd=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] > d)
                gtd = 1;
        }

        if(gtd == 0)
            cout<<"YES\n";
        else
        {
            sort(a,a+n);
            if( (a[0] + a[1]) <= d)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

        t--;
    }
    return 0;
}

