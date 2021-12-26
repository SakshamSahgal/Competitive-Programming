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
    int n,k;
    cin>>n>>k;

    int max_good = n-1;
    int min_good = 0;

    if( min_good <=k && k<= max_good)
    {
        int a[n+1];

        for(int i=2; i<=(k+1); i++)
            a[i] = i;

        int rem = (n-(k+1));
        if(rem%2 == 0)
        {
            a[1] = 1;

            for(int i=k+2;i<=n;i+=2)
            {
                a[i]=i+1;
                a[i+1]=i;
            }
        }
        else
        {
            a[1] = n;
            for(int i=k+2;i<=(n-1);i+=2)
            {
                a[i]=i+1;
                a[i+1]=i;
            }
            a[n] = 1;
        }

        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    else
        cout<<"-1\n";



    return 0;
}


