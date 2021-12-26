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

bool destroyed(int a[],int n)
{
    if(a[0] == 0 || a[n-1] == 0)
        return 1;
    else
    {
        for(int i=1; i<n-2; i++)
        {
            if(a[i] == a[i+1] && a[i] == 0)
            {
                return 1;
            }
        }
        return 0;
    }
}

void update_array(int a[],int n,int d)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] > 0)
            a[i] -= d;
    }
}

void array_printer(int a[],int n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}


int min_element_finder(int a[],int n)
{
        int mini = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i] != 0)
            mini = min(a[i],mini);
    }
    return mini;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    lli ans=0;

    while(destroyed(a,n) == 0)
    {
        int mini = (min_element_finder(a,n));
        //cout<<"min element = "<<mini<<"\n";
        ans += mini;
        update_array(a,n,mini);
       //array_printer(a,n);
    }

    cout<<ans<<"\n";

    return 0;
}


