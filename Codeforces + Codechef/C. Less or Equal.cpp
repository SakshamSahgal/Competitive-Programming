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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    if( k < n)
    {
        if(k != 0)
        {
            if(a[k-1] == a[k])
                cout<<"-1\n";
            else
                cout<<a[k-1]<<"\n";
        }
        else
        {
            if(a[0] == 1)
                cout<<"-1\n";
            else
                cout<<"1\n";
        }
    }
    else
        cout<<1000000000<<"\n";

    return 0;
}
