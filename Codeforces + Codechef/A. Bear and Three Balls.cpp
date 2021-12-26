#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
//for(usi i=0;i<n;i++)
   // cout<<" "<<a[i];

for(usi i=0;i<(n-2);i++)
    {
   for(usi j=i+1;j<(n-1);j++)
        {
        for(usi k=j+1;k<n;k++)
            {
            if( (a[k]-a[j])<=2 && (a[j]-a[i])<=2  && (a[k]-a[i])<=2 && a[i] != a[j] && a[j] != a[k] && a[i] != a[k] )
                {
                    cout<<"YES";
                    //cout<<"\n"<<a[i]<<" "<<a[j]<<" "<<a[k];
                        return 0;
                }

            }
        }
    }
cout<<"NO";
return 0;
}
