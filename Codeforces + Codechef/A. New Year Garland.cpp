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
        lli a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3,greater<int>());

        if(a[0]-1 <= (a[1]+a[2]))
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }

    return 0;
}

