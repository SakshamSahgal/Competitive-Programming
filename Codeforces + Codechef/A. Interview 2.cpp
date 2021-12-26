#include<iostream>
#include<algorithm>
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
    int n;
    cin>>n;
    int a[n];
    int b[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
        cin>>b[i];

    lli maxi=0;
    lli or1=0;
    lli or2=0;
    for(int l=0; l<n; l++)
    {
        for(int r=l; r<n; r++)
        {
            or1 = a[l];
            or2 = b[l];

            for(int i=l+1; i<=r; i++)
                or1 = or1|a[i];

            for(int i=l+1; i<=r; i++)
                or2 = or2|b[i];

            //cout<<"l = "<<l<<" r = "<<r<<"\n";
           // cout<<"or1 = "<<or1<<" or2 = "<<or2<<"\n";
            //cout<<"sum = "<<(or1+or2)<<"\n";

            if(maxi<(or1+or2))
                maxi = or1+or2;
        }

    }
    cout<<maxi<<"\n";
        return 0;
}

