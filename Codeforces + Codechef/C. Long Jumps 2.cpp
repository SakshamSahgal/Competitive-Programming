#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
        map<int,int> m;
        int a[n+1];
        int sum[n+1] = {0};
        for(int i=1;i<=n;i++)
            cin>>a[i];

        for(int i=n;i>=1;i--)
            {
                sum[i] = a[i];

                if( (i+a[i]) <= n )
                    sum[i] += sum[i+a[i]];
            }
       // cout<<"\n";
       // for(int i=1;i<=n;i++)
        //    cout<<sum[i]<<" ";
      //  cout<<"\n";
        cout<<*max_element(sum+1,sum+n+1)<<"\n";
        t--;
    }

    return 0;
}
