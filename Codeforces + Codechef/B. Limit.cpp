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

    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];

    for(int i=0; i<=n; i++)
        cin>>a[i];

    for(int i=0; i<=m; i++)
        cin>>b[i];

    if(n>m)
    {
        if( (a[0]*b[0]) > 0)
            cout<<"Infinity\n";
        else
            cout<<"-Infinity\n";
    }
    else if(n == m)
    {
        int x = a[0]/(__gcd(a[0],b[0]));
        int y = b[0]/(__gcd(a[0],b[0]));

        if( (x > 0 && y > 0) || ( x < 0 && y > 0 ) )
         cout<<x<<"/"<<y<<"\n";
        else if(x < 0 && y < 0)
        cout<<abs(x)<<"/"<<abs(y)<<"\n";
        else
            cout<<"-"<<abs(x)<<"/"<<abs(y)<<"\n";
    }

    else
        cout<<"0/1\n";

    return 0;
}


