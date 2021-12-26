#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void printer(int i,int a[])
{
    cout<<"\n-------------\n";
    for(int j=0; j<=i; j++)
    cout<<a[j]<<" ";
    cout<<"\n-------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,h;
    cin>>n>>h;
    int a[n];
    lli sum=0;
    int c=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sort(a,a+i+1,greater<int>());

        for(int j=0;j<=i;j+=2)
            sum+=a[j];

       // printer(i,a);
        //cout<<sum<<"\n";

        if(sum>h)
            break;
        else
            c++;
        sum=0;
    }

    cout<<c<<"\n";
    return 0;
}
