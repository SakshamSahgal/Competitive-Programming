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
    int k;
    cin>>k;
    while(k)
    {
        lli n,x,t;
        cin>>n>>x>>t;
        if(x>t)
            cout<<0<<"\n";
        else if(x == t)
            cout<<(n-1)<<"\n";
        else
        {
            if(n <= (t/x))
                cout<<((n-1)*n)/2<<"\n";
            else
             cout<<(n-(t/x))*(t/x) + ((((t/x)-1)*(t/x))/2)<<"\n";
        }
        k--;
    }

    return 0;
}
