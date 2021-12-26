#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
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
    int n;
    cin>>n;
    int a[n];
    lli moves=0;
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    for(int i=1;i<=n;i++)
        moves+=abs(a[i-1]-i);

    cout<<moves<<"\n";


    return 0;
}
