#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
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
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    cout<<(long long int)( abs(a[0] - a[1]) + abs(a[1] - a[n-1]) + abs(a[n-1] - a[0]) )<<"\n";
    t--;
    }
return 0;
}
