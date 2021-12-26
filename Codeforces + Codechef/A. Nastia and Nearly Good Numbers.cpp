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
    while(t--)
    {
        lli a,b;
        cin>>a>>b;
        if(b!=1)
        {
            cout<<"YES\n";
            if(b != 2 )
                cout<<(b-1)*a <<" "<<a<<" "<<a*b<<"\n";
            else
                cout<<a*((2*b)-1)<<" "<<a<<" "<<(a*b*2)<<"\n";
        }
        else
            cout<<"NO\n";
    }

    return 0;
}

