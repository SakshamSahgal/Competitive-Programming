#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
        lli a[n+1];
        a[0]=0;
        lli c=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];

        for(int i=1;i<n;i++)
        {
            lli st = ( ceil(((i+i)*(1.0))/a[i]) );
            lli ed = ( floor(((n+i)*(1.0))/a[i]) );


            if((st*a[i]-i) == i)
                st++;

            //cout<<"\ni = "<<i<<" st = "<<st<<" "<<" ed = "<<ed<<"\n";
            for(int j=st;j<=ed;j++)
            {
                //cout<<j*a[i]-i<<" ";
                if(a[j*a[i]-i]*a[i] == i+(j*a[i]-i))
                {
                   // cout<<"found at "<<i<<" "<<j*a[i]-i<<"\n";
                     c++;
                }

            }
        }
        cout<<c<<"\n";
        t--;
    }

    return 0;
}
