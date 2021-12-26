#include<iostream>
#include<algorithm>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        for(int i=4*n,j=1;j<=n;i-=2,j++)
                cout<<i<<" ";
        cout<<"\n";
        t--;
    }

    return 0;
}
