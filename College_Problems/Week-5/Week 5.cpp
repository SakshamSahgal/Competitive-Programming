#include<iostream>
using namespace std;



int main()
{
    cout<<"Enter size = ";
    int n;
    cin>>n;
    int a[n];
    int neg=0;
    bool zero=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] < 0)
            neg++;
    }

    if(neg == 0) //all positive
    {
        int mini = 1e9;
        for(int i=0;i<n;i++)
            mini = min(a[i],mini);
        cout<<mini<<"\n";
    }
    else if(neg%2 == 1)
    {
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(a[i] != 0)
                ans = ans*a[i];
        }
        cout<<ans<<"\n";
    }
    else
    {
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if( a[i] != 0 )
            ans = ans*a[i];
        }

        int max_neg = -1e9;
        for(int i=0;i<n;i++)
        {
            if(a[i] < 0)
                max_neg = max(a[i],max_neg);
        }
        cout<<(ans/max_neg)<<"\n";
    }
    return 0;
}
