#include<iostream>
#include<algorithm>
#include<vector>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);


        if(n>=2)
        {
            for(int i=n-2,j=1; i>=0 && j<=k; i--,j++)
            {
                a[n-1] += a[i];
            }
            cout<<a[n-1]<<"\n";
        }
        else
            {
                cout<<a[0]<<"\n";
            }





        t--;
    }

    return 0;
}
