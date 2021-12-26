#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli m,n;
    cin>>n>>m;
    if(n!=1)
        {
            if((n-m)<m)
            cout<<m-1;
        else
            cout<<m+1;
        }
    else
        cout<<1;
    return 0;
}

