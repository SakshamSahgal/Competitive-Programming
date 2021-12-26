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
        lli a,b;
        cin>>a>>b;
        if(a == b  && b == 0 )
            cout<<"YES\n";
        else if( (a == 0 && b != 0) || (b ==0 && a!= 0) )
            cout<<"NO\n";
        else
        {
            if( (a+b)%3 == 0  )
                cout<<"YES\n";
            else
                cout<<"NO\n";

        }
        t--;
    }

    return 0;
}
