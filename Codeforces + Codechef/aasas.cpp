#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x=0;
        cin>>n;
        int arr[n],a[n+1]= {0};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i],a[arr[i]]++;
        }
        for(int i=0; i<n-1; i++)
        {
            int s=arr[i];
            for(int j=i+1; j<n; j++)
            {
                s+=arr[j];
                if(s>n)
                    break;
                else x+=a[s],a[s]=0;
            }
        }
        cout<<x<<endl;
    }
}

