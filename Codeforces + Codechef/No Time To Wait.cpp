#include<iostream>
#include<algorithm>
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
    usi n,h,x;
    cin>>n>>h>>x;
    usi t[n];
    for(usi i=0; i<n; i++)
        cin>>t[i];


        for(usi i=0;i<n;i++)
        {
            if(t[i]>=(h-x))
                {
                cout<<"YES\n";
                goto x;
                }
        }

    cout<<"NO\n";
    x:
    return 0;
}

