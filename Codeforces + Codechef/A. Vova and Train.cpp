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
        int L,v,l,r;
        cin>>L>>v>>l>>r;
        if(l%v == 0)
            cout<<(L/v) - ((r/v) - (l/v) + 1)<<"\n";
        else
            cout<<(L/v) - ((r/v) - (l/v))<<"\n";

                t--;
    }

    return 0;
}

