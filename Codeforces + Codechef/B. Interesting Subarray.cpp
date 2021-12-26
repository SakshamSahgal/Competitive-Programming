#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
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
    int n;
    cin>>n;
    int a[n];
    long int mini = 10000000001;
    long int maxi = -1;
    int l=0,r=0;
    for(int i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(a[i]<mini)
            {
            mini = a[i];
            l=i+1;
            }

        if(a[i]>maxi)
            {
             maxi = a[i];
             r = i+1;
            }

        }
    //cout<<maxi<<" "<<mini<<"\n";
    if( (maxi-mini) >= n )
        {
        cout<<"YES\n";
        if(l>r)
            cout<<r<<" "<<l<<"\n";
        else
             cout<<l<<" "<<r<<"\n";
        }
    else
    cout<<"NO\n";

    t--;
    }


return 0;
}
