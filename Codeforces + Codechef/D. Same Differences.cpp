#include<iostream>
#include<algorithm>
#include<vector>
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
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int counter=0;
    for(int i=0;i<n;i++)
    {
            for(int j=i+1;j<n;j++)
            {
                if( (j-i) == (a[j]-a[i]) )
                   counter++;
            }
    }


    cout<<counter<<"\n";
    t--;
    }


return 0;
}
