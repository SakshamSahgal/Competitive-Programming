#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t;

cin>>t;
while(t--)
    {
    float sum = 0;
    int n;
    int m = 0;
    cin>>n>>m;
    float a[n];
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }
    sort(a,a+n);
   /* cout<<"sorted array\n";
    for(int i=0;i<n;i++)
        {
        cout<<a[i]<<" ";
        }
    cout<<"\n"; */
    for(int i=0;i<n;i++)
        {
        for(int j=i;j<n;j++)
            {
            sum += a[j]/(j+1);
            }

        }
        int b = sum;
        cout<<"\n sum = "<<sum;
        cout<<"\n m = "<<m<<"\n";
        if(b == m)
            {
            cout<<"YES\n";
            }
        else if(sum != m)
            {
            cout<<"NO\n";
            }

    }
return 0;
}
